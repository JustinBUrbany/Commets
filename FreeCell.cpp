/*************************************************************
* Author:		Justin.Urbany
* Filename:		FreeCell.cpp
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#include "FreeCell.h"
#include <iostream>
using std::cout;
using std::cin;
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
FreeCell::FreeCell()
{
	m_board = new Board;
	Deal();
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
FreeCell::~FreeCell()
{
	delete m_board;
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
void FreeCell::Deal()
{
	m_board->Deal();
	PlayAgain();
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
void FreeCell::PlayAgain()
{
	char selection = '\0';
	while (selection != 'n' && selection != 'y')
	{
		cout << "would you like to play again?(y,n):";
		cin >> selection;
	}

	if (selection == 'y')
	{
		delete m_board;
		m_board = new Board;
		Deal();
	}
}