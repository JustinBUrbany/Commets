#include "OpenCells.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
OpenCells::OpenCells()
{
	m_Open_Cells.setLength(4);
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
OpenCells::~OpenCells()
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
void OpenCells::PrintOpen()
{

	for (int i = 0; i<4; ++i)
	{
		//if(m_Open_Cells[i].GetSuit==Diamond)
		if (m_Open_Cells[i].GetRank() == 15)
		{
			cout << setw(10) << "Open";
		}
		else
		{
			m_Open_Cells[i].DisplayCard();
		}
	}



}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
int OpenCells::GetOpen()
{
	return m_open;
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
void OpenCells::SetCard(Card & card, int column)
{
	if (m_Open_Cells[column].GetRank() == 15)
	{
		m_Open_Cells[column] = card;
		m_open--;
	}
	else
	{
		cout << "Already a Card in that cell\n";
	}
}
/**********************************************************************
* Purpose:
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
Card & OpenCells::GetCard(int column)
{
	Card temp = m_Open_Cells[column];
	m_Open_Cells[column].SetRank(m_Open_Cells[column].INVALID);
	if (temp.GetRank() != 15)
	{
		m_open++;
	}

	return temp;
}