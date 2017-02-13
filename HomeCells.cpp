#include "HomeCells.h"
#include <iostream>
#include <iomanip>
using std::setw;
using std::cout;
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
HomeCells::HomeCells()
{
	m_Home_Cells.setLength(4);
	//m_Home_Cells
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
HomeCells::~HomeCells()
{
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
bool HomeCells::MoveHome(Card & card, int column)
{
	bool validmove = false;
	if (!m_Home_Cells[column].isEmpty())
	{
		Card tempcard = m_Home_Cells[column].Peek();
		if ((card.GetRank() - 1) == tempcard.GetRank() && tempcard.GetSuit() == card.GetSuit())
		{
			m_Home_Cells[column].Push(card);
			validmove = true;
		}
		else
		{
			validmove = false;
		}
	}
	else if (m_Home_Cells[column].isEmpty() && card.GetRank() == card.ACE)
	{
		m_Home_Cells[column].Push(card);
		validmove = true;
	}
	else
	{
		validmove = false;
	}
	return validmove;
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
Card HomeCells::MoveOutofHome(int column)
{
	return m_Home_Cells[column].Pop();
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
bool HomeCells::CheckAllCells()
{
	bool check_if_cards = false;

	for (int i = 0; i < 4; i++)
	{
		if (!m_Home_Cells[i].isEmpty())
		{
			check_if_cards = true;
		}
	}
	return check_if_cards;
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
bool HomeCells::CheckSingleCell(int column)
{
	bool check_if_card = true;
	if (m_Home_Cells[column].isEmpty())
	{
		check_if_card = false;
	}
	return check_if_card;
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
void HomeCells::PrintHomeCells()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_Home_Cells[i].isEmpty())
		{
			cout << setw(10) << "Open";
		}
		else
		{
			m_Home_Cells[i].Peek().DisplayCard();
		}
	}
	cout << "\n";
}