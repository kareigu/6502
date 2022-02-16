#include <string>
#include "cpu.hpp"
#include "fmt/core.h"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

CPU::CPU() {
  mem = Memory();
  mem.init_ram();
  fmt::print("CPU Initialised\n");
}

ftxui::Element CPU::print_registers() {
  auto main_registers = [&] {
    auto content = ftxui::vbox({
      ftxui::hbox({
        ftxui::text(L"ACC: "),
        ftxui::filler(),
        ftxui::text(fmt::format("{:#x}", A)) | ftxui::bold
      }) | ftxui::color(ftxui::Color::Green),
      ftxui::hbox({
        ftxui::text(L"X: "), 
        ftxui::filler(),
        ftxui::text(fmt::format("{:#x}", X)) | ftxui::bold
      }) | ftxui::color(ftxui::Color::Blue),
      ftxui::hbox({
        ftxui::text(L"Y: "), 
        ftxui::filler(),
        ftxui::text(fmt::format("{:#x}", Y)) | ftxui::bold
      }) | ftxui::color(ftxui::Color::Yellow),
    });

    return ftxui::window(ftxui::text("Main Registers"), content);
  };

  auto status_flags = [&] {
    auto content = ftxui::hbox({
      ftxui::vbox({
        ftxui::hbox({
          ftxui::text(L"N: "), 
          ftxui::text(fmt::format("{:b}", N)) | ftxui::bold
        }),
        ftxui::hbox({
          ftxui::text(L"V: "), 
          ftxui::text(fmt::format("{:b}", V)) | ftxui::bold
        }),
        ftxui::hbox({
          ftxui::text(L"-: "), 
          ftxui::text(fmt::format("{:b}", false)) | ftxui::bold
        }),
      })  | ftxui::color(ftxui::Color::Cyan) | ftxui::flex,
      ftxui::separator(),
      ftxui::vbox({
        ftxui::hbox({
          ftxui::text(L"B: "), 
          ftxui::text(fmt::format("{:b}", B)) | ftxui::bold
        }),
        ftxui::hbox({
          ftxui::text(L"D: "), 
          ftxui::text(fmt::format("{:b}", D)) | ftxui::bold
        }),
        ftxui::hbox({
          ftxui::text(L"I: "), 
          ftxui::text(fmt::format("{:b}", I)) | ftxui::bold
        }),
      }) | ftxui::color(ftxui::Color::Cyan) | ftxui::flex,
      ftxui::separator(),
      ftxui::vbox({
        ftxui::hbox({
          ftxui::text(L"Z: "), 
          ftxui::text(fmt::format("{:b}", Z)) | ftxui::bold
        }),
        ftxui::hbox({
          ftxui::text(L"C: "), 
          ftxui::text(fmt::format("{:b}", C)) | ftxui::bold
        }),
      }) | ftxui::color(ftxui::Color::Cyan) | ftxui::flex
      | ftxui::flex
    });

    return ftxui::window(ftxui::text("Status Flags"), content);
  };

  auto other_info = [&] {
    auto content = ftxui::vbox({
      ftxui::hbox({
        ftxui::text(L"SP: "),
        ftxui::filler(),
        ftxui::text(fmt::format("{:#x}", S))
      }) | ftxui::color(ftxui::Color::Gold1),
      ftxui::hbox({
        ftxui::text(L"PC: "),
        ftxui::filler(),
        ftxui::text(fmt::format("{:#x}", PC))
      }) | ftxui::color(ftxui::Color::Red),
      ftxui::hbox({
        ftxui::text(L"Memory: "),
        ftxui::filler(),
        ftxui::text(fmt::format("{:d} bytes", RAM_SIZE))
      }) | ftxui::color(ftxui::Color::Default),
    });

    return ftxui::window(ftxui::text("Other Info"), content);
  };

  auto view = ftxui::vbox({
    ftxui::hbox({
      main_registers(),
      status_flags() | ftxui::flex,
      other_info()
    })
  });

  return view;
}

ftxui::Element CPU::print_screen_ram() {
  std::vector<ftxui::Element> screen_lines(SCREEN_HEIGHT);
  for (int line_number = 0; line_number < SCREEN_HEIGHT; line_number++) {
    for (
      int line_start_addr = SCREEN_RAM_START + line_number * (BYTES_PER_CHARACTER * SCREEN_WIDTH); 
      line_start_addr < SCREEN_RAM_END;
      line_start_addr += BYTES_PER_CHARACTER * SCREEN_WIDTH
      ) {
        std::string chars_on_line = "";
        for (int char_addr = line_start_addr; char_addr < line_start_addr + BYTES_PER_CHARACTER * SCREEN_WIDTH; char_addr += BYTES_PER_CHARACTER) {
          chars_on_line.append(fmt::format("{:c}", mem[char_addr]));
        }
        screen_lines[line_number] = ftxui::text(chars_on_line);
      }
  }


  auto screen = ftxui::vbox(screen_lines);


  return ftxui::window(ftxui::text("Screen"), screen | ftxui::center);
}

ftxui::Component CPU::render_screen(bool* screen_on) {

  return ftxui::Renderer([&] { 
    *screen_on = true; 
    return ftxui::vbox({
      print_registers(),
      print_screen_ram()
    }); 
  });
}
