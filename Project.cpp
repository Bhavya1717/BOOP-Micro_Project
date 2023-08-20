#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<iomanip>
#include<cstring>
#include<fstream>

using namespace std;
void boopquiz(){
	string questions[10] = {
	"Which of the following is not a fundamental principle of object-oriented programming?",
	"What is the process of creating an instance of a class called in C++?",
	"Which access specifier in C++ allows class members to be accessible from anywhere in the program?",
	"Which keyword is used to derive a class from a base class in C++?",
	"In C++, a class can be defined inside another class. What is this called?",
	"Which operator is used to access the members of an object in C++?",
	"Which of the following is an example of polymorphism in C++?",
	"Which function is automatically called when an object is created in C++?",
	"Which keyword is used to prevent a derived class from overriding a base class method in C++?",
    "Which of the following is not a valid way to initialize an object in C++?"
						}, options[10][4] = {
	{"Encapsulation","Inheritance","Polymorphism","Abstraction"},
	{"Initializing","Constructing","Instantiating","Allocating"},
	{"public","private","protected","friend"},
	{"new","base","extend","class"},
	{"Nested class","Derived class","Abstract class","Friend class"},
	{".","::","*","->"},
	{"Function overloading","Operator overloading","Virtual functions","All of the above"},
	{"constructor","destructor","main()","friend function"},
	{"sealed","override","final","const"},
	{"Object obj = new Object();","Object obj;","Object obj();","Object obj = Object();"},
					    };
	string correctOptions[10] = {
		"Encapsulation","Constructing","public","class",
		"Nested class",".","All of the above",
		"constructor","final","Object obj = new Object();"
								};
	int userOptions[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int totalQs = 10;	
	int op;

	//----- Conducting Quiz -----
	for( int i=0; i<totalQs; i++ ){
		cout<<"Question # "<<(i+1)<<endl;
		cout<< questions[i]<<endl;
		cout<< "1."<<options[i][0]<<endl;
		cout<< "2."<<options[i][1]<<endl;
		cout<< "3."<<options[i][2]<<endl;
		cout<< "4."<<options[i][3]<<endl<<endl;
		
		cout<<"Select Option (1-4) or 0 to skip and press enter: ";
		cin >> userOptions[i];
		cout<<endl<<"-----------------------------"<<endl<<endl;
	}
	
	//----- Printing Correct Options -----
	cout<<"======= ======= ======= ======= "<<endl;
	cout<<"======= Correct Options ======= "<<endl;
	cout<<"======= ======= ======= ======= "<<endl;

	for( int i=0; i<totalQs; i++ ){
		cout<<"Question # "<<(i+1)<<endl;
		cout<< questions[i]<<endl;
		cout<< "1."<<options[i][0]<<endl;
		cout<< "2."<<options[i][1]<<endl;
		cout<< "3."<<options[i][2]<<endl;
		cout<< "4."<<options[i][3]<<endl;
		
		if( userOptions[i] == 0 ){
			cout<< "You Skipped this Question."<<endl;		
		}else{
			cout<< "You Selected : "<<options[i][userOptions[i]-1]<<endl;		
		}
		cout<< "Correct Option : "<<correctOptions[i]<<endl<<endl;

		cout<<"Press any key to continue..."<<endl;
		getch();
		cout<<endl<<"------------------"<<endl;
	}
	
	//----- Printing Result -----
	cout<<endl<<endl;
	cout<<"======= ======= ======= ======= "<<endl;
	cout<<"=======      Result     ======= "<<endl;
	cout<<"======= ======= ======= ======= "<<endl;

	class Data {
        int correct = 0;
	    int incorrect = 0;
	    int skipped = 0;
        public:
        int Correct() {return correct;}
        int InCorrect() {return incorrect;}
        int Skipped() {return skipped;}
    }d1;
    int correct = d1.Correct();
	int incorrect = d1.InCorrect();
	int skipped = d1.Skipped();
	for( int i=0; i<totalQs; i++ ){
		if( userOptions[i] != 0 ){
			if( correctOptions[i] == options[i][userOptions[i]-1] ) {
				correct++;
			}else{
				incorrect++;
			}
		}else{
			skipped++;
		}
	}
	cout<< "Total Questions : "<< totalQs <<endl;	
	cout<< "Correct : "<< correct <<endl;
	cout<< "In-Correct : "<< incorrect <<endl;
	cout<< "Skipped : "<< skipped <<endl;
	
    fstream file;
    file.open("BOOP_Quiz_Result.txt",ios::out|ios::app);
    file << "Correct is " << correct << endl;
    file << "Incorrect is " << incorrect << endl;
    file << "Skipped is " << skipped <<endl;
    file.close();

	getch();

}

int score=0;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';

void drawBoard()
 {
  system("cls");
  cout<<" "<< board[0][0] << " | "<< board[0][1] << " | " << board[0][2] <<"\n";
  cout<<"---+---+---\n";
  cout<<" "<< board[1][0] << " | "<< board[1][1] << " | " << board[1][2] << "\n";
  cout<<"---+---+---\n";
  cout<<" "<< board[2][0] << " | "<< board[2][1] << " | " << board[2][2] << "\n";
}

  void getInput() 
  {
  int x, y;
  cout<<"Enter the coordinates: ";
  cin>>x>>y;
  x--; y--;
  if (x < 0 || x > 2 || y < 0 || y > 2)
  {
    cout<<"Invalid input. Try again.\n";
    getInput();
  } 
  else if (board[x][y] != ' ')
  {
    cout<<"That space is already occupied. Try again.\n";
    getInput();
  } 
  else 
  {
    board[x][y] = player;
  }
}

char checkWinner() {
    int i,j,t;
  // check rows
  for (i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0];
    }
  }
  // check columns
  for (i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return board[0][i];
    }
  }
  // check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0];
  }
  if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
    return board[2][0];
  }
  for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(board[i][j]!=' ')
				t=1;
			else
			{
				t=0;
				break;
			}
		}
	}
	if(t==1)
		return 't';
  return ' ';
}

void reset() {
    char initialArray[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    memcpy(board, initialArray, sizeof(board));
}

string winnert;

void tictactoe() {
    char n[20],n2[20],s,winner;
    cout<<"Enter First Player Name which Sign = 'X' : ";
    cin>>n;
    cout<<"Enter Second Person Name which Sign = 'O' : ";
    cin>>n2;
    while (1)
	{
		drawBoard();
		getInput();
		winner = checkWinner();
		if (winner != ' ')
		{
			drawBoard();
			if(winner=='X') {
                cout<<"\n"<<n<<" has won!\n";
                winnert = n;
            }
			else if(winner=='O') {
                cout<<"\n"<<n2<<" has won!\n";
                winnert = n2;
            }
			else if(winner=='t')
				cout<<"\nMatch Tied";
			break;
		}
		if(player == 'X')
			player = 'O';
		else
			player = 'X';
	}
    reset();
    fstream info;
    info.open("Game_Info.txt",ios::out|ios::app);
    info << "Winner is " << winnert << endl;
    info.close();
	getch();
}

void matrices()
{
    char sign;
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;

    cout << "Enter number of rows (between 1 and 100): ";
    cin >> r;

    cout << "Enter number of columns (between 1 and 100): ";
    cin >> c;
    cout<<"Enter operation : ";
    cin>>sign;
    cout << endl << "Enter elements of 1st matrix: " << endl;
     
    
    
    switch(sign)
    {
         case  '+':

    // Storing elements of first matrix entered by user.
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";
           cin >> a[i][j];
       }

    // Storing elements of second matrix entered by user.
    cout << endl << "Enter elements of 2nd matrix: " << endl;
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element b" << i + 1 << j + 1 << " : ";
           cin >> b[i][j];
       }

    // Adding Two matrices
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
            sum[i][j] = a[i][j] + b[i][j];

    // Displaying the resultant sum matrix.
    cout << endl << "Sum of two matrix is: " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout <<  setw(4) << sum[i][j] << "  ";
            if(j == c - 1)
                cout << endl;
        }
        break;
        
        case '*':
        // Storing elements of first matrix entered by user.
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";
           cin >> a[i][j];
       }

    // Storing elements of second matrix entered by user.
    cout << endl << "Enter elements of 2nd matrix: " << endl;
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element b" << i + 1 << j + 1 << " : ";
           cin >> b[i][j];
       }

    // Multiplying Two matrices
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
            sum[i][j] = a[i][j] * b[i][j];

    // Displaying the resultant product matrix.
    cout << endl << "Product of two matrix is: " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << sum[i][j] << "  ";
            if(j == c - 1)
                cout << endl;
        }
        break;
        
        case '-':
        // Storing elements of first matrix entered by user.
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";
           cin >> a[i][j];
       }

    // Storing elements of second matrix entered by user.
    cout << endl << "Enter elements of 2nd matrix: " << endl;
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element b" << i + 1 << j + 1 << " : ";
           cin >> b[i][j];
       }

    // Subtracting Two matrices
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
            sum[i][j] = a[i][j] * b[i][j];

    // Displaying the resultant difference matrix.
    cout << endl << "Difference of two matrix is: " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << sum[i][j] << "  ";
            if(j == c - 1)
                cout << endl;
        }
        break;
        
        case '/':
        // Storing elements of first matrix entered by user.
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";
           cin >> a[i][j];
       }

    // Storing elements of second matrix entered by user.
    cout << endl << "Enter elements of 2nd matrix: " << endl;
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element b" << i + 1 << j + 1 << " : ";
           cin >> b[i][j];
       }

    // Dividing Two matrices
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
            sum[i][j] = a[i][j] / b[i][j];

    // Displaying the resultant quotient matrix.
    cout << endl << "Quotient of two matrix is: " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << sum[i][j] << "  ";
            if(j == c - 1)
                cout << endl;
        }
        break;
        default:
            cout<<"Invalid Choice";
    }
	getch();
}

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls"); //system("clear");
    for (int i = 0; i < width+2; i++)
    {
        cout << "#";
    }
    cout << endl;
 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "@";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                 
 
            if (j == (width - 1))
                cout << "#";
        }
        cout << endl;
    }
 
    for (int i = 0; i < (width+2); i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    //if (x > width || x < 0 || y > height || y < 0)
    //  gameOver = true;
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
 
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
 
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
void snakegame()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10); //sleep(10);
    }
    fstream file;
    file.open("Snake_Info.txt",ios::out|ios::app);
    file << "You scored " << score << " in snake game." << endl;
    file.close();
}

void start();

void metadata() {
    cout<<"First  Creator Name: Bhavya N. Gohil 226400307066"<<endl;
    cout<<"Second Creator Name: Harshil Patel   226400307072"<<endl;
    cout<<"Third  Creator Name: Shweta Gajjar   226400307059"<<endl;
    cout<<"Fourth Creator Name: Arpan Christian 226400307033"<<endl;
    Sleep(4000);
    start();
}

void start() {
    do{
		system("cls");
		cout<<" -------------------------- "<<endl; 
		cout<<" |   Multi-Task Program   | "<<endl; 
		cout<<" --------------------------"<<endl;
		cout<<"1. BOOP Quiz"<<endl;	 
		cout<<"2. Matrices Sum"<<endl;
		cout<<"3. Snake Game"<<endl;
		cout<<"4. Tic-Tac-Toe"<<endl;
		cout<<"5. Exit"<<endl;
		char op = getche();
		system("cls");	
        if( op=='1') boopquiz();
		else if( op=='2') matrices();
		else if( op=='3') snakegame();
		else if( op=='4') tictactoe();
		else if( op=='5') exit(0);
        else if( op=='m') metadata();
		
	}while(1);
}

int main()
{
    start();
	getch();
}