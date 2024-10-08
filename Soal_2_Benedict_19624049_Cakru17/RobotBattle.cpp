#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int basestats[99][4] = { //basestats[main body code][HP=0, ATK=1, DEF=2, SPD=3]
    {0,0,0,0},      //Null
    {150,50,50,50}, //MB01
    {170,30,75,25}, //MB02
    {155,80,40,25}, //MB03
    {125,70,35,70}, //MB04
    {175,65,55,5},  //MB05
    {170,35,35,60}, //MB06
    {147,84,70,84}  //MB07
};
int upgradestats[99][4] = { //upgradestats[upgrade code][HP=0, ATK=1, DEF=2, SPD=3]
    {0,0,0,0},      //UP00
    {0,5,0,-5},     //UP01
    {0,-5,5,0},     //UP02
    {-5,5,-5,5},    //UP03
    {5,0,0,-5},     //UP04
    {15,-5,-5,-5},  //UP05
    {0,-5,-5,10},   //UP06
    {7,-7,7,-7},    //UP07
    {-5,+15,-5,-5}, //UP08
    {0,5,5,-10},    //UP09
    {-5,-5,15,-5}   //UP10
};
int mainBodyAmount = 6;
int engineAmount = 16;
int weaponAmount = 11;
int upgradeAmount = 10;
string mainBodyNames[7] = {"All-Rounder","Defender","Crusader","Striker","Bruiser","Cruiser","Gambler"};
string engineNames[16] = {"Drain","Reflect","Clutch","Expansion","Conserve","Rejuvenation","Dice","Precision","Damper","Contingency","Accelerator","Momentum","Standby","Hail-Mary","Perpetuation","Delibilation"} ;
string weaponNames[11] = {"Electromagnetic Pulsar","Malware Injector","Repair Drones","Stun Baton","Comically Large Sword","Light Ray","Slot Machine","Messy Wiring","Battering Ram","Water Pistol","Riot Shield"};
string specialNames[11] = {"E.M.P. Burst","Hot Singles in Your Area","Fixer Upper","Brutal Shock","Big Ass Swing","Flash Destruction","All In","Safety Violations","Tank Charge","Waterlog","Field of Barriers"};
string upgradedetails[10] = {"(+Atk, -Spd)","(+Def, -Atk)","(+Atk, + Spd, -Def, -HP)","(+HP, -Spd)","(+++HP, -Atk, -Def, -Spd)","(++Spd, -Atk, -Def)","(+HP, +Def, -Atk, -Spd)","(+++Atk,-HP,-Def,-Spd)","(+Atk, +Def, --Spd)","(+++Def, -Atk, -HP, -Spd)"};

bool YesOrNo () {
    string a;
    bool b;
    do {
        cout<<"[Y/N] :";
        cin>>a;
        if(a!="Y" && a!="N") 
            cout<<"Please input Y or N!"<<endl;
    }while(a!="Y" && a!="N");

    if(a=="Y") 
        b=true;
    else 
        b=false;
    
    return b;
}

void spaceOut(int a) {
    int i;
    for(i = 0; i < a; i++) 
        cout<<" ";
}

int digitCount(int a) {
    int n,t;
    n=1;
    t=10;
    do {
      if(a >= t)
        n++;
        t=t*10;
    }while(a >= t);
    return n;
}

string prefix0(int a) {
    if (a <10)
        return "0";
    else
        return "";
}

class Robot {
    public: 
    int mbodyt, engine1, engine2, weapon, upgrade, currentHP;
    bool lost, defendState, disabledState, virusState, stunnedState, ignoreFortifications, clutchState, contingencyState, inverseState, standbyUsage, hailmaryUsage, trueGambler;
    int defendCooldown, disabledCooldown, virusTimer, specialCount, attackCount, shieldLayers, inverseTimer;
    int stats[4]; //stats[HP=0, ATK=1, DEF=2, SPD=3]
    string name;
    void buildRobot() {
        int i;
        cout<<endl<<"Main Body"<<endl;
        cout<<"----------"<<endl;
        for(i = 0; i < mainBodyAmount; i++) {
            cout<<"<MB"<<prefix0(i + 1)<<i + 1<<"> "<<mainBodyNames[i]<<endl;
        }
        do {
            cout<<endl<<"Pick a Main Body!"<<endl<<">MB";
            cin>>mbodyt;
            cout<<endl;

            if(mbodyt == 0 || mbodyt > mainBodyAmount) 
                cout<<"Please input a valid part code!"<<endl;
        }while(mbodyt == 0 || mbodyt > mainBodyAmount);
        
        cout<<endl<<"Engine"<<endl;
        cout<<"----------"<<endl;
        for(i = 0; i < engineAmount; i++) {
            cout<<"<EN"<<prefix0(i + 1)<<i + 1<<"> "<<engineNames[i]<<" Engine"<<endl;
        }
        do {
            do {
                cout<<endl<<"Pick Engine 1!"<<endl<<">EN";
                cin>>engine1;

                if(engine1 == 0 || engine1 > engineAmount) 
                    cout<<"Please input a valid part code!"<<endl;
            }while(engine1 == 0 || engine1 > engineAmount);

            do {
                cout<<endl<<"Pick Engine 2!"<<endl<<">EN";
                cin>>engine2;

                if(engine2 == 0 || engine2 > engineAmount) 
                        cout<<"Please input a valid part code!"<<endl;
            }while(engine2 == 0 || engine2 > engineAmount);

            if (engine1==engine2)
                cout<<endl<<"Can't have 2 of the same Engine type"<<endl;
        }while(engine1==engine2);

        cout<<endl<<"Weapon"<<endl;
        cout<<"----------"<<endl;
        for(i = 0; i < weaponAmount; i++) {
            cout<<"<WP"<<prefix0(i + 1)<<i + 1<<"> "<<weaponNames[i]<<endl;
        }
        do {
            cout<<endl<<"Pick a Weapon!"<<endl<<">WP";
            cin>>weapon;
            if(weapon == 0 || weapon > weaponAmount) 
                cout<<"Please input a valid part code!"<<endl;
        }while(weapon == 0 || weapon > weaponAmount);

        cout<<endl<<"Upgrade"<<endl;
        cout<<"----------"<<endl;
        for(i = 0; i < upgradeAmount; i++) {
            cout<<"<UP"<<prefix0(i + 1)<<i + 1<<"> "<<upgradedetails[i]<<endl;
        }
        do {
            cout<<endl<<"Pick an Upgrade!"<<endl<<">UP";
            cin>>upgrade;
            if(upgrade == 0 || upgrade > upgradeAmount) 
                cout<<"Please input a valid part code!"<<endl;
        }while(weapon == 0 || upgrade > upgradeAmount);

        cout<<endl<<"Give it a Name!"<<endl<<">";
        cin>>name;
        cout<<endl;
    }
    void clearRobot() {
        mbodyt=0;
        engine1=0;
        engine2=0;
        weapon=0;
        upgrade=0;
        name="";
        stats[0]=0;
        stats[1]=0;
        stats[2]=0;
        stats[3]=0;
    }
    void setStats() {
        int i;
        if(engineCheck(07) == true && weapon == 07 && upgrade == 07)
            mbodyt = 07;
        for(i =  0; i < 4; i++) {
            stats[i] = basestats[mbodyt][i] + upgradestats[upgrade][i];
        }
    }
    bool engineCheck(int a) {
        bool e;
        if ((engine1 == a || engine2 == a) && disabledState == false) {
            e = true;
        }
        else {
            e = false;
        }

        return e;
    }
    void initialStates() {
        defendState = false;
        disabledState = false;
        virusState = false;
        stunnedState = false;
        ignoreFortifications = false;
        clutchState = false;
        contingencyState = false;
        inverseState = false;
        standbyUsage = false;
        hailmaryUsage = false;
        trueGambler = false;
        defendCooldown = 0;
        disabledCooldown = 0;
        virusTimer =  0;
        if (engineCheck(05) == true) 
            specialCount = 2;
        else if(engineCheck(07) == true && weapon == 07 && upgrade == 07) {
            specialCount = 777;
            trueGambler = true;
        }
        else
            specialCount = 1;
        attackCount = 0;
        shieldLayers = 0;
        inverseTimer = 0;
        lost = false;
    }
};

int HPbarcount (Robot a) {
    int h;
    h = (a.currentHP * 20) / a.stats[0];
    if(h==0) 
        h = 1;
    return  h;
}

void turnTimer (int a) {
    if (a > 0) {
        a--;
    }
}

void displaySaveSlots(Robot m[10]) {
    int i;
    for(i = 0; i < 10; i++) {
        cout<<"Save Slot "<<i+1<<" : ";
        if(m[i].name=="") 
            cout<<"Empty Slot"<<endl;
        else
            cout<<m[i].name<<endl;
    }
}

int perStat(int a, int x) {
    int i = 0;
    do {
        a = a - x;
        if (a > 0)
            i++;
    }while(a > 0);

    return i;
}

void swapStats(int a, int b) {
    int atemp = a;
    int btemp = b;
    b = atemp;
    a = btemp;
}

class Battle {
    public:
    Robot Player1, Player2;
    void setPlayers(Robot a[10]) {
        int i,pick;
        Player1.clearRobot();
        Player2.clearRobot();
        displaySaveSlots(a);
        do {
            cout<<"Player 1 : ";
            cin>>pick;

            if(a[pick - 1].name=="") 
                cout<<"Please pick a non-empty save slot!"<<endl;
        }while(a[pick - 1].name=="");
        Player1 = a[pick - 1];

        do {
            cout<<"Player 2 : ";
            cin>>pick;

            if(a[pick - 1].name=="") 
                cout<<"Please pick a non-empty save slot!"<<endl;
        }while(a[pick - 1].name=="");
        Player2 = a[pick - 1];
    }
    void displayHealthBars() {
        int i,k;
        cout<<Player1.name;
        spaceOut(50 - (Player1.name.length() + Player2.name.length()));
        cout<<Player2.name<<endl;
        for(i = 0; i < 20; i++) 
            cout<<"_";
        spaceOut(10);
        for(i = 0; i < 20; i++) 
            cout<<"_";
        cout<<endl;

        for(i = 0; i < HPbarcount(Player1) - 1; i++)
            cout<<"_";
        cout<<"/";

        for (i = 0; i < Player1.shieldLayers; i++)
            cout<<")";

        spaceOut(50 - HPbarcount(Player1) - HPbarcount(Player2) - Player1.shieldLayers - Player2.shieldLayers);

        for (i = 0; i < Player2.shieldLayers; i++)
            cout<<"(";

        cout<<"\\";
        for(i = 0; i < HPbarcount(Player2) - 1; i++)
            cout<<"_";
        cout<<endl;

        cout<<Player1.currentHP<<"/"<<Player1.stats[0];
        spaceOut(48 - (digitCount(Player1.currentHP) + digitCount(Player1.stats[0]) + digitCount(Player2.currentHP) + digitCount(Player2.stats[0])));
        cout<<Player2.currentHP<<"/"<<Player2.stats[0]<<endl<<endl;
    }
    bool critRoll (Robot a) {  
        bool c;
        int i;
        i = rand() % 101;

        if (i < 15 && a.engineCheck(8) == true)
            c = true;
        else if (i < 5)
            c = true;
        else
            c = false;
        return c;
    }
    int perpetuationBonus (Robot&a) {
        if(a.engineCheck(15) == true) {
            cout<<a.name<<"'s Perpetuation Engine lengthened the effect!"<<endl<<endl;
            return 1;
        }
        else {
            return 0;
        }
    }
    int damageCalc (Robot& a, Robot& b, bool c, int pwr) {
        int damageTaken, staticBoost, relfectdmg;
        double crit, random, defend, virus, engineBoost;
        random = (100 + (rand() % 11))/100;
        engineBoost = 1;
        staticBoost = 0;

        if (c == true) {
            crit = 1.2;
            cout<<a.name<<" landed a Critical Hit!"<<endl;
        }
        else 
            crit = 1;

        if (b.defendState == true && a.ignoreFortifications == false) {
            defend = 1.5;
            cout<<b.name<<" partially blocked the attack!"<<endl;
        }
        else 
            defend = 1;

        if (b.shieldLayers > 0 && a.ignoreFortifications == false) {
            pwr = 0;
            cout<<b.name<<"'s shield fully blocked "<<a.name<<"'s attack!"<<endl;
            b.shieldLayers--;
        }
        else if (b.shieldLayers > 0 && (a.ignoreFortifications == true || c == true)) {
            cout<<a.name<<"'s attack broke through "<<b.name<<"'s shield";
            if (b.shieldLayers > 1) 
                cout<<"s";
            cout<<"!"<<endl;
            b.shieldLayers = 0;
        }

        if (a.virusState == true) { 
            virus = 0.7;
            cout<<"The virus weakened "<<a.name<<"'s attack!"<<endl;
        }
        else {
            virus = 1;
        }

        if(a.engineCheck(03) == true && a.clutchState == true) {
            engineBoost = engineBoost * 1.3;
            cout<<a.name<<"'s Clutch Engine boosted the attack!"<<endl;
        }

        if(a.engineCheck(04) == true) {
            engineBoost = engineBoost * (0.5 + (a.attackCount * 0.3));
            if(a.attackCount > 0) {
                cout<<a.name<<"'s Expansion Engine is accumulating strength!"<<endl;
            }
        }

        if(a.engineCheck(12) == true) {
            staticBoost = staticBoost + 0.1*a.stats[3];
            cout<<a.name<<"'s Momentum Engine is converting it's speed into additional strength!"<<endl;
        }

        damageTaken = (pwr * (a.stats[1] / (b.stats[2] * defend)) * random * crit * virus * engineBoost) + staticBoost;

        if (damageTaken > 0) {
            cout<<a.name<<" dealt "<<damageTaken<<" HP to "<<b.name<<endl<<endl;
        }

        if (b.engineCheck(02) == true) {
            cout<<b.name<<"'s Reflect Engine deflected some of the attack back to "<<a.name<<"!"<<endl;
            relfectdmg = 0.4 * damageTaken;
            a.currentHP = a.currentHP - relfectdmg;
            cout<<a.name<<" lost "<<relfectdmg<<" HP!"<<endl<<endl;
        }

        if (a.engineCheck(16) == true && a.attackCount == 0) {
            b.stunnedState = true;
            cout<<a.name<<"'s Debilitation Engine has stunned "<<b.name<<"!"<<endl<<endl;
        }

        a.attackCount++;
        return damageTaken;
    }
    int healCalc (Robot a, int b, double x, int s) {
        int heal;
        heal = (b * x) + s;

        if (a.currentHP + heal > a.stats[0])
            heal = a.stats[0] - a.currentHP;

        cout<<a.name<<" has repaired itself for "<<heal<<" HP!"<<endl;
        return heal;
    }
    void specialCheck (Robot& a, Robot& b) {
        cout<<a.name<<" unleashed it's Special : "<<specialNames[a.weapon-1]<<"!"<<endl<<endl;

        switch(a.weapon) {
            case 1:
                b.currentHP = b.currentHP - damageCalc(a, b, false, 50);
                b.disabledState = true;
                b.disabledCooldown = 2 + perpetuationBonus(a);
                cout<<b.name<<"'s engines has been disabled for "<<b.disabledCooldown<<" turns!"<<endl<<endl;
                break;

            case 2:
                b.virusState = true;
                b.virusTimer = 3 + perpetuationBonus(a);
                cout<<b.name<<" has been inflicted with a virus for "<<b.virusTimer<<" turns!"<<endl<<endl;
                break;

            case 3:
                cout<<a.name<<" is rapidly repairing itself!"<<endl<<endl;
                a.currentHP = a.currentHP + healCalc(a, a.stats[0], 0.5, 0);
                break;

            case 4:
                b.currentHP = b.currentHP - damageCalc(a, b, false, 50);
                b.stunnedState = true;
                cout<<b.name<<" has been stunned!"<<endl<<endl;
                break;

            case 5:
                cout<<a.name<<" swings it's Comically Large Sword "<<b.name<<"!"<<endl<<endl;
                b.currentHP = b.currentHP - damageCalc(a, b, false, 100);
                break;

            case 6:
                cout<<a.name<<" broke "<<b.name<<"'s fortifications!"<<endl<<endl;
                a.ignoreFortifications = true;
                b.currentHP = b.currentHP - damageCalc(a, b, false, 65);
                a.ignoreFortifications = false;
                break;

            case 7: {
                cout<<a.name<<" takes the gamble!"<<endl<<endl;
                int g[3], i, matchType, matchAmount, debuffRandom, effectRandom;
                int match[5] = {0, 0, 0, 0, 0};
                string gs[3];
                debuffRandom = rand() % 3;

                for (i = 0; i < 3; i++) {
                    g[i] = rand() % 12;

                    if (g[i] < 3) {
                        gs[i] = "O"; //deal damage
                        match[0]++;
                    }
                    else if (g[i] < 6) {
                        gs[i] = "^"; //attack boost
                        match[1]++;
                    }
                    else if (g[i] < 9) {
                        gs[i] = "*"; //inflict debuff
                        match[2]++;
                    }
                    else if (g[i] < 11) {
                        gs[i] = "X"; //do nothing if not match 3, insta-lose if does match 3
                        match[3]++;
                    }
                    else {
                        gs[i] = "7";//do nothing if not match 3, insta-win if does match 3
                        match[4]++;
                    }
                }

                cout<<"["<<gs[0]<<"]["<<gs[1]<<"]["<<gs[2]<<"]"<<endl<<endl;

                matchAmount = 0;
                for (i = 0; i < 5; i++) {
                    if(match[i] > 1) {
                        matchAmount = match[i];
                        matchType = i;
                    }
                }

                cout<<a.name<<" landed on ";
                if(matchAmount > 1) {
                    cout<<"match "<<matchAmount;
                    switch(matchType) {
                        case 0:
                            cout<<" [O]s! It deals ";
                            if (matchAmount == 2) {
                                cout<<"moderate damage!"<<endl<<endl;
                                b.currentHP = b.currentHP - damageCalc(a, b, false, 50);
                            }
                            else if (matchAmount == 3) {
                                cout<<"heavy damage!"<<endl<<endl;
                                b.currentHP = b.currentHP - damageCalc(a, b, true, 70);
                            }
                            break;

                        case 1:
                            cout<<" [^]s! It boosts it's attack stat ";
                            if (matchAmount == 2) {
                                cout<<"slightly!"<<endl<<endl;
                                a.stats[1] = a.stats[1]*1.1;
                            }
                            else if (matchAmount == 3) {
                                cout<<"significantly!"<<endl<<endl;
                                a.stats[1] = a.stats[1]*1.4;
                            }
                            break;

                        case 2:
                            cout<<" [*]s! It ";
                            if (matchAmount == 2) {
                                if (debuffRandom == 0) {
                                    b.virusState = true;
                                    b.virusTimer = 2 + perpetuationBonus(a);
                                    cout<<"inflicted a virus to "<<b.name<<" for "<<b.virusTimer<<" turns!";
                                }
                                else if (debuffRandom == 1) {
                                    b.disabledState = true;
                                    b.disabledCooldown = 2 + perpetuationBonus(a);
                                    cout<<"disabled "<<b.name<<"'s engines for "<<b.disabledCooldown<<" turns!";
                                }
                                else {
                                    b.inverseState = true;
                                    b.inverseTimer = 2 + perpetuationBonus(a);
                                    cout<<"inverted "<<b.name<<"'s attack and defense stats for "<<b.inverseTimer<<" turns!";
                                }
                                cout<<endl<<endl;
                            }   
                            else if (matchAmount == 3) {
                                int universalTimer = 3 + perpetuationBonus(a);
                                b.virusState = true;
                                b.virusTimer = universalTimer;
                                b.disabledState = true;
                                b.disabledCooldown = universalTimer;
                                b.inverseState = true;
                                b.inverseTimer = universalTimer;
                                cout<<" massively debuffed "<<b.name<<"by inflicting a virus to it, disabled its engines, and inverted its attack and defense stats for "<<universalTimer<<" turns!"<<endl<<endl;
                            }
                            break;

                        case 3:
                            cout<<" [X]s! It ";
                            if (matchAmount == 2) {
                                cout<<"does nothing...";
                            }
                            else if (matchAmount == 3) {
                                cout<<"lost the gamble and made itself self-destruct!!!";
                                a.currentHP = 0;
                            }
                            cout<<endl<<endl;
                            break;

                        case 4:
                            cout<<" [7]s! It ";
                            if (matchAmount == 2) {
                                cout<<"does nothing...";
                            }
                            if (matchAmount == 3) {
                                cout<<"won the gamble and made "<<b.name<<" self-destruct!!!";
                                b.currentHP = 0;
                            }
                            cout<<endl<<endl;
                            break;
                    }
                }
                else {
                    cout<<" no matches... It ";
                    effectRandom = rand() % 5;

                    switch(effectRandom) {
                        case 0:
                            cout<<"damages itself."<<endl<<endl;
                            a.currentHP = a.currentHP - damageCalc(a, a, false, 50);
                            break;

                        case 1:
                            cout<<"lowers its own attack stat."<<endl<<endl;
                            a.stats[1] = a.stats[1] * 0.75;
                            break;

                        case 2:
                            a.virusState = true;
                            a.virusTimer = 2  + perpetuationBonus(a);
                            cout<<"inflicted a virus on itself for "<<a.virusTimer<<" turns."<<endl<<endl;
                            break;

                        case 3:
                            a.disabledState = true;
                            a.disabledCooldown = 2  + perpetuationBonus(a);
                            cout<<"disabled its own engines for "<<a.disabledCooldown<<" turns."<<endl<<endl;
                            break;

                        case 4:
                            a.inverseState = true;
                            a.inverseTimer = 2  + perpetuationBonus(a);
                            cout<<"inverted its own attack and defense stats for "<<a.inverseTimer<<" turns."<<endl<<endl;
                            break;
                    }
                }
                break;
            }
            
            case 8:
                b.currentHP = b.currentHP - (a.stats[0] - a.currentHP);
                cout<<a.name<<" dealt "<<a.stats[0] - a.currentHP<<" HP to "<<b.name<<" from its own damages!"<<endl<<endl;
                break;

            case 9:
                cout<<a.name<<" rammed itself on to "<<b.name<<"!"<<endl<<endl;
                b.currentHP = b.currentHP - damageCalc(a, b, false, 50 * a.stats[2] / a.stats[1]);
                break;

            case 10:
                b.inverseState = true;
                b.inverseTimer = 3 + perpetuationBonus(a);
                cout<<a.name<<" inverted "<<b.name<<"'s attack and defense stats for "<<b.inverseTimer<<" turns!"<<endl<<endl;
                swapStats(b.stats[1], b.stats[2]);
                break;

            case 11:
                a.shieldLayers = a.shieldLayers + perStat(a.stats[2], 30);
                cout<<a.name<<" generated "<<perStat(a.stats[2], 35)<<" shield layers!"<<endl<<endl;
                break;
        }
    }
    void loseCheck(Robot& a) {
        if(a.currentHP <= 0 && a.lost == false) {
            if(a.engineCheck(13) == true && a.standbyUsage == false) {
                a.currentHP = 1;
                cout<<a.name<<"'s is still holding on thanks to its Standby Engine!"<<endl<<endl;
                a.standbyUsage = true;
            }
            else {
                a.lost = true;
                a.currentHP = 0;
                cout<<a.name<<" has stopped functioning!"<<endl;
            }
        }
    }
    void HPCheck (Robot& a, Robot& b) {
        if (a.engineCheck(03) == true && a.clutchState == false && a.currentHP < 0.5*a.stats[0]) {
            cout<<a.name<<"'s Clutch Engine has activated!"<<endl<<endl;
            a.clutchState = true;
        }

        if (a.engineCheck(10) == true && a.contingencyState == false && a.currentHP < 0.3*b.stats[0]) {
            cout<<a.name<<"'s Contingency Engine has activated a shield!"<<endl<<endl;
            a.shieldLayers++;
            a.contingencyState = true;
        }

        if (a.engineCheck(14) == true && a.hailmaryUsage == false && a.currentHP < 0.1*a.stats[0]) {
            cout<<a.name<<"'s Hail-Mary Engine has activated!"<<endl<<endl;
            specialCheck(a, b);
            a.hailmaryUsage = true;
        }
    }
    void playerTurn(Robot& a, Robot& b) {
        char action1;
        int damage;
        bool turndone, critHit, canDo;
        cout<<a.name<<"'s Turn"<<endl;

        if (a.engineCheck(05) == true && a.specialCount == 1) {
            cout<<a.name<<"'s Conserve Engine has conserved enough power for a second Special!"<<endl<<endl;
        }

        if (a.engineCheck(8) == true) {
            cout<<a.name<<"'s Precision Engine has made it more likely to land a critical hit!"<<endl<<endl;
        }

        if (a.inverseState == true) {
            cout<<a.name<<"'s attack and defense stats are inverted"<<endl<<endl;
        }

        cout<<"<1>Attack"<<endl;
        cout<<"<2>Defend"<<endl;
        cout<<"<3>Special"<<endl;
        
        do {
            do {
                cout<<"Pick an action : ";
                cin>>action1;
                cout<<endl<<endl;
                canDo = true;

                if((action1 == '2') && (a.defendCooldown > 0)) {
                    cout<<"You can't defend twice in a row!"<<endl<<endl;
                    canDo = false;
                }

                if(action1 == '3' && a.specialCount == 0) {
                    cout<<a.name<<" has already unleashed it's Special!"<<endl<<endl;
                    canDo = false;
                }
                
                if(action1 == '3' && a.specialCount == 1 && (a.engine1 == 05 || a.engine2 == 05) && a.disabledState == true) {
                    cout<<a.name<<"'s Conserve Engine is disabled! "<<a.name<<" can't draw power from it to unleash another Special!"<<endl<<endl;
                    canDo = false;
                }

                if((action1 == '1' || action1 == '2') && a.trueGambler == true) {
                    cout<<"A true gambler only takes the gamble..."<<endl<<endl;
                    canDo = false;
                }
            }while(canDo == false);


            turndone = true;
            switch(action1) {
                case '1':
                    a.defendState = false;
                    critHit = critRoll(a);
                    damage = damageCalc(a, b, critHit, 35);
                    b.currentHP = b.currentHP - damage;
                    if (a.engineCheck(01) == true) {
                        cout<<a.name<<"'s Drain Engine drained some of "<<b.name<<"'s energy!"<<endl;
                        a.currentHP = a.currentHP + healCalc(a, damage, 0.3, 0);
                    }
                    break;

                case '2':
                    a.defendState = true;
                    a.defendCooldown = 2;
                    cout<<a.name<<" goes into a defensive stance!"<<endl;
                    break;

                case '3':
                    specialCheck(a, b);
                    a.specialCount--;
                    break;

                default :
                    cout<<"Please pick a valid action!"<<endl;
                    turndone = false;
                    break;
            }
        }while(turndone==false);
    }
    void battleTurn(Robot& a, Robot& b) {
        displayHealthBars();
        if (a.stunnedState == false) {
            playerTurn(a, b);
            loseCheck(b);
            loseCheck(a);
            HPCheck(a, b);
            HPCheck(b, a);
            loseCheck(b);
            loseCheck(a);
        }
        else {
            cout<<a.name<<" is stunned!"<<endl;
            a.stunnedState = false;
        }
        cout<<endl<<endl;
        if (b.lost == false && a.lost == false) {
            displayHealthBars();
            if (b.stunnedState == false) {
                playerTurn(b, a);
                loseCheck(a);
                loseCheck(b);
                HPCheck(b, a);
                HPCheck(a, b);
                loseCheck(a);
                loseCheck(b);
            }
            else {
                cout<<b.name<<" is stunned!"<<endl;
                b.stunnedState = false;
            }
        }
    }
    void turnEvents(Robot& a,  int x) {
        if (a.engineCheck(06) == true && a.currentHP < a.stats[0]) {
            cout<<a.name<<"'s Rejuvenation Engine is automatically repairing it's body!"<<endl<<endl;
            a.currentHP = a.currentHP + healCalc(a, a.stats[0], 0.083, 0);
        }
       
       
        if (a.virusState == true) {
            if (a.virusTimer > 0) {
                a.currentHP = a.currentHP - (a.stats[0]/12);
                cout<<a.name<<" took "<<a.stats[0]/12<<" HP of damage from the virus!"<<endl<<endl;
            }
            else {
                a.virusState = false;
                cout<<"The virus on "<<a.name<<" has been deleted!"<<endl<<endl;
            }
            a.virusTimer--;
        }

        if (a.disabledState ==  true) {
            if (a.disabledCooldown == 0) {
                a.disabledState = false;
                cout<<a.name<<"'s engines are no longer disabled!"<<endl<<endl;
            }
            a.disabledCooldown--;
        }

        if (a.inverseState == true) {
            if (a.inverseTimer == 0) {
                a.inverseTimer = false;
                swapStats(a.stats[1], a.stats[2]);
                cout<<a.name<<"'s stats have returned to normal!"<<endl<<endl;
            }
            a.inverseTimer--;
        }

        if (a.engineCheck(11) == true) {
            cout<<a.name<<"'s Acceleration Engine is accelerating it's speed!"<<endl<<endl;
            a.stats[3] = a.stats[3] * (1 + (x *0.2));
        }

        if (a.engineCheck(07) == true) {
            int buffRandom = rand() % 6;

            cout<<a.name<<"'s Dice Engine ";
            
            switch(buffRandom) {
                case 0:
                    cout<<"raised it's attack stat!";
                    a.stats[1] = a.stats[1]*1.2;
                    break;

                case 1:
                    cout<<"raised it's defense stat!";
                    a.stats[2] = a.stats[2]*1.2;
                    break;
                
                case 2:
                    cout<<"raised it's speed stat!";
                    a.stats[3] = a.stats[3]*1.2;
                    break;

                case 3:
                    cout<<"lowered it's attack stat!";
                    a.stats[1] = a.stats[1]*0.83;
                    break;

                case 4:
                    cout<<"lowered it's defense stat!";
                    a.stats[2] = a.stats[2]*0.83;
                    break;
                
                case 5:
                    cout<<"lowered it's speed stat!";
                    a.stats[3] = a.stats[3]*0.83;
                    break;
            }
            cout<<endl<<endl;
        }

        if (a.defendCooldown > 0)
            a.defendCooldown--;
    }
    void start_fight() {
        bool Player1first;
        int turnAmount = 1;
        cout<<endl<<endl<<Player1.name<<" Vs "<<Player2.name<<endl<<endl;
        cout<<"Battle Start!"<<endl<<endl;
        Player1.currentHP = Player1.stats[0];
        Player2.currentHP = Player2.stats[0];
        Player1.initialStates();
        Player2.initialStates();

        if(Player1.engineCheck(9) == true) {
            Player1.shieldLayers++;
            cout<<Player1.name<<"'s Damper Engine has activated a shield!"<<endl<<endl;
        }

        if(Player2.engineCheck(9) == true) {
            Player2.shieldLayers++;
            cout<<Player2.name<<"'s Damper Engine has activated a shield!"<<endl<<endl;
        }

        do {
            cout<<"Turn "<<turnAmount<<"!"<<endl<<endl;

            if(Player1.stats[3] > Player2.stats[3]) 
                Player1first = true;
            else if(Player1.stats[3] == Player2.stats[3]) 
                Player1first = rand() % 2;
            else 
                Player1first = false;

            if(Player1first == true) 
                battleTurn(Player1, Player2);
            else 
                battleTurn(Player2, Player1);

            if (Player1.lost == false && Player2.lost == false) {
                
                turnEvents(Player1, turnAmount);
                loseCheck(Player1);
                HPCheck(Player1, Player2);
                loseCheck(Player2);
                loseCheck(Player1);

                turnEvents(Player2, turnAmount);
                loseCheck(Player2);
                HPCheck(Player2, Player1);
                loseCheck(Player1);
                loseCheck(Player2);

                turnAmount++;
                cout<<endl<<endl<<endl<<endl;
            }
        }while(Player1.lost == false && Player2.lost == false);

        if(Player1.lost == false && Player2.lost == true) {
            cout<<Player1.name<<" has won the battle!"<<endl<<endl;
        }
        else if (Player1.lost == true && Player2.lost == false) {
            cout<<Player2.name<<" has won the battle!"<<endl<<endl;
        }
        else {
            cout<<"Both "<<Player1.name<<" and "<<Player2.name<<" have stopped functioning!"<<endl<<"The battle ends in a draw!"<<endl;
        }
    }
};

class Game {
    public: 
    int i, pick,pickSaveSlot;
    void add_robot(Robot a[10]) {
        bool cont = false;
        do {
        cout<<"Create a Robot"<<endl;
        cout<<"--------------"<<endl;
        displaySaveSlots(a);
        
        cout<<"Pick Save Slot : ";
        cin>>pick;

        pickSaveSlot=pick - 1;
        a[pickSaveSlot].buildRobot();
        cout<<"Do you wish to create this Robot?";
        if(YesOrNo()==false) 
            a[pickSaveSlot].clearRobot();
        else
            cont=true;
        a[pickSaveSlot].setStats();
        }while(cont==false);
    }
    void displayDetails(Robot a[10]) {
        displaySaveSlots(a);
        cout<<"Pick Save Slot : ";
        cin>>pick;
        cout<<endl<<endl;

        pickSaveSlot=pick - 1;
        cout<<"Name           : "<<a[pickSaveSlot].name<<endl;
        cout<<"Main Body Type : <MB"<<prefix0(a[pickSaveSlot].mbodyt)<<a[pickSaveSlot].mbodyt<<"> "<<mainBodyNames[a[pickSaveSlot].mbodyt]<<endl;
        cout<<"Engine 1       : <EN"<<prefix0(a[pickSaveSlot].engine1)<<a[pickSaveSlot].engine1<<"> "<<engineNames[a[pickSaveSlot].engine1]<<endl;
        cout<<"Engine 2       : <EN"<<prefix0(a[pickSaveSlot].engine2)<<a[pickSaveSlot].engine2<<"> "<<engineNames[a[pickSaveSlot].engine2]<<endl;
        cout<<"Weapon         : <WP"<<prefix0(a[pickSaveSlot].weapon)<<a[pickSaveSlot].weapon<<"> "<<weaponNames[a[pickSaveSlot].weapon]<<endl;
        cout<<"Upgrade        : <UP"<<prefix0(a[pickSaveSlot].upgrade)<<a[pickSaveSlot].upgrade<<"> "<<upgradedetails[a[pickSaveSlot].upgrade]<<endl<<endl;
        cout<<"Robot Stats"<<endl;
        cout<<"Health  : "<<a[pickSaveSlot].stats[0]<<endl;
        cout<<"Attack  : "<<a[pickSaveSlot].stats[1]<<endl;
        cout<<"Defense : "<<a[pickSaveSlot].stats[2]<<endl;
        cout<<"Speed   : "<<a[pickSaveSlot].stats[3]<<endl;
    }
    void start_game(Robot a[10]) {
        Battle fight;
        fight.setPlayers(a);
        fight.start_fight();
    }
};

int main() {
    char action;
    int i;
    bool canPlay = false;
    Game playGame;
    Robot SaveSlots[10];
    srand(time(0));
    
    cout<<"Welcome to Robot Battle"<<endl<<endl;
    playGame.add_robot(SaveSlots);
    
    do {
        cout<<endl<<endl<<endl;
        cout<<"1. Create a Robot"<<endl;
        cout<<"2. Show Robot details"<<endl;
        cout<<"3. Battle"<<endl;
        cout<<"0. End Program"<<endl;
        cout<<"Action : ";
        cin>>action;
        
        cout<<endl<<endl<<endl;


        switch (action) {
            case '1':
                playGame.add_robot(SaveSlots);
                break;

            case '2':
                playGame.displayDetails(SaveSlots);
                break;

            case '3':
                playGame.start_game(SaveSlots);
                break;
                
            case '0':
                break;
            
            default:
                cout<<endl<<"Pick a valid action!"<<endl<<endl;
            
        }
    }while(action!=0);
}
