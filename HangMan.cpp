#include <iostream>
#include <conio.h> 
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

using namespace std;

string cword(int lvl){ //function to choose word according to level
    string word;//local variable word
    srand((unsigned)time(0));
    //dictionary for level 1
    string dictionary1[30]={"apple", "cat", "sun", "blue", "happy", "smile", "water", "tree", "book", "moon", "song", "bird", "green", "flower", "star", "play", "cloud", "red", "child", "ocean", "home", "friend", "light", "sweet", "dream", "jump", "magic", "soft", "simple", "laugh"};
    //dictionary for level 2 
    string dictionary2[30]={"brazil", "japan", "australia", "mexico", "canada", "india", "france", "argentina", "pakistan", "thailand", "spain", "italy", "egypt", "germany", "russia", "china", "palestine", "chile", "norway", "greece", "sweden", "turkey", "portugal", "netherlands", "giki", "vietnam", "ireland", "malaysia", "peru", "denmark"};
    //dictionary for level 3
    string dictionary3[30]={"elephant", "guitar", "ocean", "mountain", "camera", "jungle", "firefly", "rainbow", "island", "butterfly", "whisper", "adventure", "silence", "harmony", "secret", "captain", "illusion", "journey", "serenade", "symphony", "mystery", "enchant", "courage", "horizon", "serenity", "celestial", "glisten", "lullaby", "radiant", "whimsical"};

    switch (lvl){
        case(1):
        word=
        dictionary1[rand()%30];
        break;
        case(2):
        word= dictionary2[rand()%30];
        break;
        case(3):
        word= dictionary3[rand()%30];
        break;
        default:
        word= dictionary3[rand()%30];
        break;
    }
    return word;
}

int menu(int j,int a,int b,int signal){
    char ca,cb;
     int p=0;
    string outputs[5]={"-> Continue\nStart New Game\nQuit\n","Continue\n-> Start New Game\nQuit\n","Continue\nStart New Game\n-> Quit\n","-> Start\nQuit\n","Start\n-> Quit\n"};
    do{
    if(signal==1){
    system("cls");
    cout << "\033[38;2;128;0;128m";
    cout << "                    __    __       ___      .__   __.   _______ .___  ___.      ___      .__   __.\n";
    cout << "                   |  |  |  |     /   \\     |  \\ |  |  /  _____||   \\/   |     /   \\     |  \\ |  |\n";
    cout << "                   |  |__|  |    /  ^  \\    |   \\|  | |  |  __  |  \\  /  |    /  ^  \\    |   \\|  |\n";
    cout << "                   |   __   |   /  /_\\  \\   |  . `  | |  | |_ | |  |\\/|  |   /  /_\\  \\   |  . `  |\n";
    cout << "                   |  |  |  |  /  _____  \\  |  |\\   | |  |__| | |  |  |  |  /  _____  \\  |  |\\   |\n";
    cout << "                   |__|  |__| /__/     \\__\\ |__| \\__|  \\______| |__|  |__| /__/     \\__\\ |__| \\__|\n\n";
    }
    if(p!=0&&signal==0){
    cout << "\033[F\033[K"; 
    cout << "\033[F\033[K"; 
    cout << "\033[F\033[K";  
    }
    cout << "\033[32m";
    cout<<outputs[j];
    cout << "\033[37m";
    p++;
    ca=getch();
    if(ca==char(224)){
        cb=getch();
        if(cb=='H'&& j!=a){
            j--;
            Beep(500,50);
        }
        else if(cb=='P'&& j!=b){
            j++;
            Beep(500,50);
        }   
    }
    }while(ca!=char(13));
    Beep(1500,500);
    return j;
}
int hintmenu(){ 
    int c2=0,p=0;
    char a,b;
    string choice[2]={"-> Yes    No\n","   Yes -> No\n"}; 
    do{
        if(c2!=0){
            cout <<"\033[F\033[K";
            cout <<"\033[F\033[K";
            cout <<"\033[F\033[K";
        }
        cout<<"\nWould you like a hint : "<<endl;
        cout << "\033[32m";
        cout<<choice[p];
        cout << "\033[37m";
        a=getch();
        if(a==char(224)){
            b=getch();
            if(b=='M'&&p!=1){
                p++;
                Beep(500,50);
            }
            if(b=='K'&&p!=0){
                p--;
                Beep(500,50);
            }
        }    
        c2++;
    }while(a != char(13));
    Beep(1500,500);
    return p;
}

string spaces(string word){ //function to create a a string of _ that denotes hidden word
    string spaces="";
    for (int i=0;i<word.length();i++){
        spaces+='_';
    }
    return spaces;
}

void drawing(int wgl){//function that draws the current state of hangman using wrong guesses made
    switch(wgl){
        case 6 :
            cout<<"\n\t+---+\n\t|   |\n\t    |    \n\t    |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 5 :
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n\t    |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 4 : 
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n\t|   |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 3 :
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n\t|\\  |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 2:
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n       /|\\  |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 1:
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n       /|\\  |\n       /    |\n\t    |\t\n\t=======\n";
            break;
        case 0:
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n       /|\\  |\n       / \\  |\n\t    |\t\n\t=======\n";
            break;
    }
}

bool check(char inp,string word,int &cg,int &wgl,string entered){//function checking to see if entered .character is present in word
    int pre=0;
    for (int i=0;i<word.length();i++){//check to see if alphabet is present 
            if (inp==word[i]){
                cg++;
                return true;
            }
        }  

    for(int k=0;k<entered.length();k++){//if not present make sure it hasnt been entered before ,if eneterd no of wrong guesses is not increased
        pre=(inp==entered[k]?1:pre);
        
    }
    wgl-=(pre==0?1:0);
    return false;
}
void placement(char inp,string word,string &gword,int &cg,int &wgl,string entered){//function that places correct alphabet entered in correct place
    if(check(inp,word,cg,wgl,entered)==true){//checks if alphabet is present
        for (int i=0;i<word.length();i++){
            if (inp==word[i]){
                gword[i]=inp;//placement
            }
        }  
    }
}

void status(int cg,int wgl,string gword,int win,int loss,int lvl){ //function to print current status of game with statistics,drawing and blank spaces/amount of word guesssed
    system("cls");
    cout << "\033[38;2;128;0;128m";//change color of text thatbis cout
    cout << "                    __    __       ___      .__   __.   _______ .___  ___.      ___      .__   __.\n";//output hangman text design on status bar
    cout << "                   |  |  |  |     /   \\     |  \\ |  |  /  _____||   \\/   |     /   \\     |  \\ |  |\n";
    cout << "                   |  |__|  |    /  ^  \\    |   \\|  | |  |  __  |  \\  /  |    /  ^  \\    |   \\|  |\n";
    cout << "                   |   __   |   /  /_\\  \\   |  . `  | |  | |_ | |  |\\/|  |   /  /_\\  \\   |  . `  |\n";
    cout << "                   |  |  |  |  /  _____  \\  |  |\\   | |  |__| | |  |  |  |  /  _____  \\  |  |\\   |\n";
    cout << "                   |__|  |__| /__/     \\__\\ |__| \\__|  \\______| |__|  |__| /__/     \\__\\ |__| \\__|\n\n";
    cout << "\033[37m";//color back to normal
    cout<<"\n\nCorrect Guesses : "<<cg<<"\tIncorrect Guesses Left : "<<wgl<<"\tWins : "<<win<<"\tLoss : "<<loss<<"\tLevel : "<<lvl<<endl<<endl; //status
    drawing(wgl);
    cout<<gword<<endl;
}

endgame(int wgl,string word,string gword,int cg,int lvl,int &win,int &loss){ //checks to see if game meets conditions to end game 
    if(gword==word){//if word is guesses correctly
        win++;//increment win
        status(cg,wgl,gword,win,loss,lvl);//print status
        cout<<"\n\n\t\tCongrats on Winning The Game !!\n\n";
        return false;
    }
    else if(wgl==0){//if word isnt guesses in guesses
        loss++;
        status(cg,wgl,gword,win,loss,lvl);
        cout<<"\n\n\t\tYou Lost !! The word was : "<<word<<endl<<endl;
        return false;
    }
return true;
}

void hint(int wgl,string &gword,string word,int &hintnum){//function to give hint 
    bool only1=0; 
    int count=0,p=0;

    for(int k=0;k<gword.length();k++){//make sure hint is only given if more than one alphabet is guesses 
        count+=(gword[k]=='_'?1:0);
    }
    for(int i1=0;i1<word.length();i1++){/////////error in this part
        for(int i2=i1+1;i2<word.length();i2++){
            if(word[i1]==word[i2] && gword[i2]=='_'){
                count--;
                i2=word.length();
            }
        }
    }
   
    only1=(count<=1?1:0);
    if(hintnum==0 && only1==0){//conditions to offer hint
        char want;
        if(wgl<=2){//condition to offer hint
            p=hintmenu();
            if(p==0){//action
                hintnum++;
                for(int i=0;i<gword.length();i++){
                    if(gword[i]=='_'){
                        gword[i]=word[i];
                        for(int k=0;k<word.length();k++){
                            if(word[k]==word[i]){
                                gword[k]=word[k];
                            }
                        }
                        i=gword.length();
                    }
                }
            }
        }
    }
}
char input(){//function to get correct and relavent input 
     char inptchar;
    do{
        cout<<"Enter A Character : ";
        cin>>inptchar;
        inptchar=(int(inptchar)<97 && int(inptchar)>=65?char(int(inptchar)+32):inptchar);
    }while(int(inptchar)<97||int(inptchar)>122);
return inptchar;
}

void lvlupdate(int &points,int win,int loss,int &lvl){//function to update level of dificulty of game
    points=win-loss;
    if (points >=3){
    lvl = 3;
    } 
    else if (points == 1 || points ==2){
    lvl = 2;
    }
    else if (points <= 0){
    lvl = 1;
    }
}

int main(){
        if(menu(3,3,4,1)==3){
            restart:
            int lvl=1,points=0,win=0,loss=0,cont;//variables that are needed throught execution of program to keep stats on game
            do{
                string word= cword(lvl),gword=spaces(word),entered="*"; //initialise and get words
                int cg=0,wgl=6,hintnum=0;//current game statistics
                char inp;//input variable
                bool loop=true;
                while (loop){
                    status(cg,wgl,gword,win,loss,lvl);//print game status
                    inp=input();//get input
                    placement(inp,word,gword,cg,wgl,entered); //place input char into blank space if correct guess
                    entered+=inp;  // add input character to string of characters entered
                    hint(wgl,gword,word,hintnum);//function for hint
                    loop = endgame(wgl,word,gword,cg,lvl,win,loss);     //endgame function
                }
                cont=menu(0,0,2,0);
                lvlupdate(points,win,loss,lvl);//update level
            }while (cont == 0);// continue game if entered yes
            if(cont==1){
                goto restart;
            }
        }     
    system("cls");
    cout << "\033[31m";
    cout << "Credits:\n"<< "1) Rayyan Hassan Salman            2023601  Section-H  CS\n"<< "2) Sahibzada Muhammad Asad Shayan  2023629  Section-H  CS\n"<< "3) Yahya Qadeer Dar                2023759  Section-H  CS";
    cout << "\033[37m";
    Beep(0,7000);
    return 0;
}