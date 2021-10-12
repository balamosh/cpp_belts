#include <string>
#include <list>
#include "test_runner.h"
using namespace std;

class Editor {
public:
	// Реализуйте конструктор по умолчанию и объявленные методы
	Editor();
	void	Left();
	void	Right();
	void	Insert(char token);
	void	Cut(size_t tokens = 1);
	void	Copy(size_t tokens = 1);
	void	Paste();
	string	GetText() const;
private:
	list<char>				text;
	list<char>				buffer;
	list<char>::iterator	cursor;

	list<char>::iterator	CursorOffset(size_t tokens = 1);
};

Editor::Editor() {
	cursor = text.begin();
}

void	Editor::Left() {
	if (cursor != text.begin()) {
		--cursor;
	}
}

void	Editor::Right() {
	if (cursor != text.end()) {
		++cursor;
	}
}

void	Editor::Insert(char token) {
	text.insert(cursor, token);
}

list<char>::iterator	Editor::CursorOffset(size_t tokens) {
	list<char>::iterator	offset_pos = cursor;
	for (size_t i = 0; i < tokens; ++i) {
		if (offset_pos == text.end()) {
			break ;
		}
		++offset_pos;
	}
	return (offset_pos);
}

void	Editor::Cut(size_t tokens) {
	list<char>::iterator	new_cursor = CursorOffset(tokens);
	buffer = {cursor, new_cursor};
	text.erase(cursor, new_cursor);
	cursor = new_cursor;
}

void	Editor::Copy(size_t tokens) {
	buffer = {cursor, CursorOffset(tokens)};
}

void	Editor::Paste() {
	if (!buffer.empty()) {
		text.insert(cursor, buffer.begin(), buffer.end());
	}
}

string	Editor::GetText() const {
	string	ret(text.begin(), text.end());
	return (ret);
}



void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);
    
    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;
    
    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();
    
    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }
  
  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");
  
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  return 0;
}