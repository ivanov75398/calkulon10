#include "stack.h"

int main()
{
	int VAL = 0;
	stack DO(100), UNDO(100);
	UNDO.push(0);

	int op = -1;
	while (op != 4)
	{
		system("cls");
		cout<< "VAL=" << VAL << "\n" << endl;
		cout<< "UNDO:" << UNDO << "\n" << endl;
		cout<< "DO:" << DO << "\n" << endl;
		cout<<"0. +"<<endl;
		cout<<"1. -"<<endl;
		cout<<"2. UNDO" << endl;
		cout<<"3. DO" << endl;
		cout<<"4. exit" << endl;

		cin >> op;

		switch (op)
		{
			case 0:
			{
				int k;
				cout << "VAL += ";
				cin >> k;
				VAL += k;
				UNDO.push(VAL);
				DO.refreshIndex();
				break;
			}

			case 1:
			{
				int k;
				cout << "VAL -= ";
				cin >> k;
				VAL -= k;
				UNDO.push(VAL);
				DO.refreshIndex();
				break;
			}

			case 2:
			{
				if (UNDO.stackEMPTY()) break;
				DO.push(UNDO.pop());
				VAL = UNDO.GetVAL();
				break;
			}

			case 3:
			{
				if (DO.stackEMPTY()) break;
				UNDO.push(DO.pop());
				VAL = UNDO.GetVAL();
				break;
			}

			case 4:
			{
				return 0;
			}
		}
	}
	return 0;
}