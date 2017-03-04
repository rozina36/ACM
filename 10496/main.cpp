////
////  main.cpp
////  10496
////
////  Created by Rozina Akter Ruma on 4/3/17.
////  Copyright © 2017 Rozina Akter Ruma. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
//long testCase;
//
//void pSwap(char *a,char *b) {
//    char temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void
//
//void permute(char a[], int i, int n)
//{
//    int j;
//    if (i == n) {
//        cout << a << endl;
//        
//    }
//    else
//    {
//        for (j = i; j <= n; j++)
//        {
//            pSwap(&a[i], &a[j]);
//            permute(a, i+1, n);
//            pSwap(&a[i], &a[j]);
//        }
//    }
//} 
//
//int main() {
//    
//    cin>>testCase;
//    
//    char perm[] = "0123456789";
//    permute(perm, 0, 2);
//    
//    for(int i=1;i<=testCase;i++) {
//      long  startX,startY,totalPos,posArray[30][2],gridSizeX,gridSizeY;
//        
//        cin>>gridSizeX>>gridSizeY;
//        cin>>startX>>startY;
//        cin>>totalPos;
//        
//        for(int m=0;m<gridSizeX;m++) {
//            //for (int n=0; n<gridSizeY; n++) {
//                cin>>posArray[m][0]>>posArray[m][1];
//            //}
//        }
//        
//    
//    }
//
//
//
//    //cout<<"This is the end";
//
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>

int N, M;
int startX,  startY;
int numberOFbeppers;
int arr[103][103];
int per[103],used[103];

int shortestLength;
int tempResult;
bool isPointsSame = false;

void flodfill(int x, int y,int destX, int destY,int res)
{
    int cnt  = res;
    
    if (x == destX && y == destY)
    {
        isPointsSame = true;
        tempResult = cnt;
        return;
    }
    
    //if (x < 0 || x == N+1 || y < 0 || y == M+1)
    //    return;
    
    if(x != destX){
        if (isPointsSame==false) {
            if(x>destX) //Top
            {
                
                flodfill(x - 1, y, destX, destY, cnt + 1);
            }
            else {
                flodfill(x + 1, y, destX, destY, cnt + 1);
            }
        }
    }
    if(y != destY){
        if (isPointsSame==false) {
            if(y>destY)//Left {
            {
                flodfill(x, y - 1,destX, destY, cnt + 1);
            }
            else {
                flodfill(x, y + 1, destX, destY, cnt + 1);
            }
        }
    }
}


void print()
{
    int sum =0;
    //printf("%d ", per[i]);
    flodfill(startX,startY,arr[per[0]][0],arr[per[0]][1],0);
    sum = sum + tempResult;
    isPointsSame = false;
    for(int i=0; i<numberOFbeppers-1; i++){
        flodfill(arr[per[i]][0],arr[per[i]][1],arr[per[i+1]][0],arr[per[i+1]][1],0);
        sum = sum + tempResult;
        isPointsSame = false;
    }
    flodfill(arr[per[numberOFbeppers-1]][0],arr[per[numberOFbeppers-1]][1],startX,startY,0);
    sum = sum + tempResult;
    isPointsSame = false;
    
    if (shortestLength > sum)
        shortestLength = sum;
}

void solve(int index)
{
    if (index == numberOFbeppers)
    {
        print();
        return;
    }
    
    for (int i = 0; i < numberOFbeppers; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            per[index] = i;
            solve(index + 1);
            used[i] = 0;
        }
    }
    
}



int main()
{
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d", &N, &M);
        scanf("%d%d", &startX, &startY);
        scanf("%d", &numberOFbeppers);
        
        for (int i = 0; i < numberOFbeppers; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                scanf("%d", &arr[i][j]);
            }
            
        }
        for (int i = 0; i < numberOFbeppers; i++)
            used[i] = 0;
        shortestLength = 1000000;
        solve(0);
        
        printf("The shortest path has length %d\n", shortestLength);
    }
    
    
    
    //system("PAUSE");
    return 0;
}
