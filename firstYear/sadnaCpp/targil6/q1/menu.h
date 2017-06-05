#ifndef __MENU_H
#define __MENU_H

enum MenuOption {
	 EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY,
	 FIRST_MENU_OPTION = EXIT, LAST_MENU_OPTION = EMPTY
};

MenuOption menu();

#endif // __MENU_H