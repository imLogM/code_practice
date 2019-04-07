编程试题：求数列的和

        使用语言：JAVA
        参考正解代码如下：

import java.util.*;
class Main{
public static void main(String args[]){
        int m;
        double sum,n;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            n=sc.nextInt();
            m=sc.nextInt();
            sum=0;
            for(int i=0;i<m;i++){
                sum=sum+n;
                n=Math.sqrt(n);
            }
            System.out.printf("%.2f",sum);
            System.out.println();
        }
    }
}




        使用语言：C++
参考正解代码如下：

#include <math.h>
#include <stdio.h>
int main()
{
    int n;
    double x, s;

    while (~scanf("%lf%d", &x, &n))
    {
        for(s = 0.0; n--; x = sqrt(x))
            s += x;
        printf("%.2lf\n", s);
    }   return 0;
}




使用语言：C#
参考正解代码如下：

using System;

namespace myApp
{
    class Program
    {
    public static void Main()
        {
            string line;
            string[] p;
            int m, n;
            double nn;
            while (!string.IsNullOrEmpty(line = Console.ReadLine()))
            {
                p = line.Split(' ');
                n = int.Parse(p[0]);
                m = int.Parse(p[1]);
                double sum = 0;
                nn = n;
                for (int i = 0; i < m; i++)
                {
                    sum = sum + nn;
                    nn = Math.Sqrt(nn);
                }
                Console.WriteLine(string.Format("{0:f}", sum));
            }
        }
    }
}




使用语言：JavaScript
        参考正解代码如下：

var m;
var sum,n;
var sc

while(sc = read_line()){
var arr = sc.split(' ');
n=parseInt(arr[0]);
m=parseInt(arr[1]);
sum=0;
for(var i=0;i<m;i++){
sum=sum+n;
n=Math.sqrt(n);
}
print(sum.toFixed(2));
}




编程试题：水仙花

        使用语言：JAVA
        参考正解代码如下：

import java.util.Scanner;
public class Main{
public static void main(String args[]){
        Scanner reader=new Scanner(System.in);
        while(reader.hasNextInt()){
            int m=reader.nextInt();
            int n=reader.nextInt();
            if(100<=m&&m<=n&&n<=999){
                int j=0;
                for(int i=m;i<=n;i++)
                {
                    int geWei,shiWei,baiWei;
                    baiWei=i/100;
                    shiWei=(i-baiWei*100)/10;
                    geWei=i-baiWei*100-shiWei*10;
                    if(i==geWei*geWei*geWei+shiWei*shiWei*shiWei+baiWei*baiWei*baiWei)
                    {j=j+1;
                        if(j>1){
                            System.out.print(" "+i);
                        }
                        else{
                            System.out.print(i);
                        }

                    }
                }
                if(j==0){
                    System.out.print("no");
                }
                System.out.println();
            }
        }
    }
}




        使用语言：C++
参考正解代码如下：

#include<stdio.h>

int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        int t=0;
        for(int i=m; i<=n; i++){
            int a=i/100;
            int b=i%100/10;
            int c=i%10;

            if(i==a*a*a+b*b*b+c*c*c && t==0){
                printf("%d ",i);
                t++;
            }
            else if(i==a*a*a+b*b*b+c*c*c && t==1){
                printf("%d ",i);
            }
        }
        if(t!=0){ printf("\n"); }
        if(t==0){ printf("no\n"); }
    }
    return 0;
}



使用语言：C#
参考正解代码如下：

using System;

namespace myApp
{
    class Program
    {
    public static void Main()
        {
            string line;
            string[] p;
            int m, n;

            while ((line = Console.ReadLine()) != null)
            {
                p = line.Split(' ');
                n = int.Parse(p[1]);
                m = int.Parse(p[0]);
                var j=0;
                for(var i=m;i<=n;i++)
                {
                    int geWei,shiWei,baiWei;
                    baiWei = (i/100);
                    shiWei = ((i-baiWei*100)/10);
                    geWei = i-baiWei*100-shiWei*10;
                    if(i==geWei*geWei*geWei+shiWei*shiWei*shiWei+baiWei*baiWei*baiWei)
                    {
                        j=j+1;
                        if(j>1) {
                            Console.Write(" "+i);
                        }
                        else {
                            Console.Write(i);
                        }
                    }
                }
                if(j==0) {
                    Console.Write("no");
                }
                Console.Write("\r\n");
            }
        }
    }
}


使用语言：JavaScript
        参考正解代码如下：

var sc;
while(sc = read_line()){
var arr = sc.split(' ');
n=parseInt(arr[1]);
m=parseInt(arr[0]);
if(100<=m&&m<=n&&n<=999){
var out = [];
var j=0;
for(var i=m;i<=n;i++)
{
var geWei,shiWei,baiWei;
baiWei=parseInt(i/100);
shiWei=parseInt((i-baiWei*100)/10);
geWei=i-baiWei*100-shiWei*10;
if(i==geWei*geWei*geWei+shiWei*shiWei*shiWei+baiWei*baiWei*baiWei)
{
j=j+1;
if(j>1){
out.push(" "+i);
}
else{
out.push(i);
}
}
}
if(j==0){
out.push("no");
}
print(out.join(''));
}
}