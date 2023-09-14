#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::Box mainBox, firstNameBox, lastNameBox;
  Gtk::Label firstNameLabel, lastNameLabel;
  Gtk::Entry firstNameEntry, lastNameEntry;
  Gtk::Button button;
  Gtk::Label resultLabel;

  Window()
      : mainBox(Gtk::Orientation::ORIENTATION_VERTICAL),
        firstNameBox(Gtk::Orientation::ORIENTATION_VERTICAL),
        lastNameBox(Gtk::Orientation::ORIENTATION_VERTICAL) {
    set_title("Name Combiner"); // Set the window title

    // Set the labels' text
    firstNameLabel.set_text("First Name:");
    lastNameLabel.set_text("Last Name:");

    button.set_label("Combine Names");

    // Add the widgets to the firstName and lastName boxes
    firstNameBox.pack_start(firstNameLabel);
    firstNameBox.pack_start(firstNameEntry);
    lastNameBox.pack_start(lastNameLabel);
    lastNameBox.pack_start(lastNameEntry);

    // Add widgets to main box
    mainBox.pack_start(firstNameBox);
    mainBox.pack_start(lastNameBox);
    mainBox.pack_start(button);
    mainBox.pack_start(resultLabel);

    add(mainBox); // Add mainBox to window
    show_all();   // Show all widgets

    // Initialize button as insensitive
    button.set_sensitive(false);

    // Signal handlers
    auto update_button_sensitivity = [this]() {
      bool should_enable =
          !firstNameEntry.get_text().empty() && !lastNameEntry.get_text().empty();
      button.set_sensitive(should_enable);
    };

    firstNameEntry.signal_changed().connect([this, update_button_sensitivity]() {
      update_button_sensitivity();
    });

    lastNameEntry.signal_changed().connect([this, update_button_sensitivity]() {
      update_button_sensitivity();
    });

    button.signal_clicked().connect([this]() {
      auto first_name = firstNameEntry.get_text();
      auto last_name = lastNameEntry.get_text();
      auto full_name = first_name + " " + last_name;
      resultLabel.set_text("Combined Name: " + full_name);
    });
  }
};

int main() {
  auto app = Gtk::Application::create();
  Window window;
  return app->run(window);
}
