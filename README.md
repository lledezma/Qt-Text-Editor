# Qt Text Editor

A simple text editor application built with Qt Widgets.

## Features

- Create new text files
- Open and edit existing `.txt` documents
- Save and "Save As" functionality
- Copy, cut, paste, select all, and deselect text
- Convert text to HTML format (experimental)
- Status bar displays the current file name

## Getting Started

### Prerequisites

- Qt 5 or later (with Qt Widgets module)
- C++17 compatible compiler

### Building

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/Qt-Text-Editor.git
    cd Qt-Text-Editor
    ```
2. Open `Qt-Text-Editor.pro` in Qt Creator **or** build from the command line:
    ```sh
    qmake Qt-Text-Editor.pro
    make
    ```

### Running

After building, run the executable generated in your build directory.

## Usage

- Use the toolbar or menu to create, open, save, or edit text files.
- Use the "Tools" menu to convert the current text to HTML format.
- The status bar shows the current file name.

## File Structure

- `main.cpp`: Application entry point
- `mainwindow.h` / `mainwindow.cpp`: Main window logic and UI slots
- `mainwindow.ui`: UI layout (Qt Designer format)
- `Qt-Text-Editor.pro`: Qt project file
- `resources.qrc`: Resource file for icons (not included in this README)
- `.gitignore`: Standard ignore rules

## Acknowledgements

Built with [Qt](https://www.qt.io/) and C++.