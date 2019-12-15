#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::Save(ofstream& OutFile, GOType Type)
{
	if (Type == card)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << cardNumber << "\t" << temp.GetCellNum() << "\t" << walletAmount << endl; //there is still a missing implementation
	}
	else { return; }
}
void CardTwo::Load(ifstream& Infile, GOType Type, CellPosition& start2, CellPosition& end2)
{
	if (Type == card)
	{

		int wallet;
		Infile >> wallet;
		walletAmount = wallet;


	}
}
void CardTwo::ReadCardParameters(Grid* pGrid)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	pOut->PrintMessage("New CardTwo: Enter its wallet amount ...");
	walletAmount = pIn->GetInteger(pOut);

	// [ Note ]:
	// In CardTwo, the only parameter of CardOne is the "walletAmount" value to increase from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Increment the wallet of pPlayer by the walletAmount data member of CardOne
	int newwalletamount = pPlayer->GetWallet();
	newwalletamount += walletAmount;
	pPlayer->SetWallet(newwalletamount);
}