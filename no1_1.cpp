#include<iostream>
#include<iomanip>
using namespace std;

bool isLunarYear(int year) { //判断平闰年 
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else 
		return 0;
} 

int monthDay(int year, int m) { //判断月份的天数 
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else if (isLunarYear(year) && m == 2)
        return 29;
    else if (!isLunarYear(year) && m == 2)
        return 28;
    else
        return 30;
}

int getFirstWeekDay(int year){ //计算该年的第一天是周几 
	int time = year - 2000;
	int weekNum = 6; 
	//int sumDays = 0;
	int plus = 0;
	if(time > 0) {
		for(int i = 2000; i < year; i++) {
			//sumDays += (isLunarYear(i) ? 366 : 365);
			//计算该年距离2000年的第一天有多少天 
			plus += (isLunarYear(i) ? 2 : 1);
		}
		weekNum = (weekNum + plus) % 7;
		return weekNum;
	} 
	else if(time < 0) {
		for(int i = 1999; i >= year; i--) {
			//sumDays += (isLunarYear(i) ? 366 : 365);
			plus += (isLunarYear(i) ? 2 : 1); 
			//由于365%7=1,366%7=2，故可以进行简化 
		}
		weekNum = (weekNum - (plus % 7) + 7) % 7; 
		//由于年份在2000前，故应将多余的天数模7减去，在加7保证计算的正确 
		return weekNum;
	}
	else
		return weekNum;
		//2000年第一天已知为周六 
}


int fillDays(int firstday, int days, int *A) {
	for(int i = 1; i <= days; i++){
		*(A + firstday++) = i;
	}
 
	return firstday;
}

void print(int *A, int start, int end) {
	while(start <= end) {
		if(*(A + start) == 0){
			cout << setw(3) << " ";
		}else{
			cout << setw(3) << *(A + start);
		}
 
		start++;
	}
}


void display(){
	cout << "欢迎来到万年历" <<endl;
	cout << "请输入查询年份(1900~9999): ";
} 

void play() {
	
	int YEAR;
	cin >> YEAR;
	if(YEAR > 9999 || YEAR < 1900){
		cout<<"输入有误"<<endl;
		return ;
	}
	cout << setw(35) << YEAR << "年" << endl;
	
	int days;
	int firstDay = getFirstWeekDay(YEAR);
	int month = 1;
	
	for(int i = 0; i < 4; i++) {
		cout << setw(12) << month << setw(23) << (month + 1) << setw(23) << (month + 2) << endl;
		cout << " 日 一 二 三 四 五 六   日 一 二 三 四 五 六   日 一 二 三 四 五 六" << endl;
		int A[3][42] = {0};
		
		days = monthDay(YEAR, month);
		firstDay = fillDays(firstDay, days, A[0]) % 7;
		month++;
		days = monthDay(YEAR, month);
		firstDay = fillDays(firstDay, days, A[1]) % 7;
		month++;
		days = monthDay(YEAR, month);
		firstDay = fillDays(firstDay, days, A[2]) % 7;
		month++;
		
		
		for(int j = 0, start = 0, end = 6; j < 6; j++) {
			print(A[0], start, end);
			cout << "  ";
			print(A[1], start, end);
			cout << "  ";
			print(A[2], start, end);
			cout << endl;
 
			start += 7;
			end += 7;
		}
	
	}
} 


int main(){
	display();
	play();
	return 0;
}
















