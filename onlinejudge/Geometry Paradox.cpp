#include<iostream>
#include<sstream>
#include<cmath>
#include<stdio.h>
#include<string>
#define PI 2*acos(0.0)


using namespace std;


int main()
{

    int t;
    cin >> t;
    string s;
    // !!!!!!
    getchar();
    while (t--)
    {

        getline(cin, s);
        double a, b, ans;

        if (sscanf(s.c_str(), "%lf %lf", &a, &b) == 1)
        {
            //1/4 * t^2 = R^2 - (R-2*b)^2
            // t^2
            //  = 4 *[ (a+b)^2 -((a+b) -2b)^2]
            //  = 4 *[ a^2 +2ab + b^2 -(a^2 -2ab + b^2)]
            //  = 4 *[4ab] ==> 16 * ab


            // ans = R^2 - a^2 - b^2
            //     = a^2 +2ab + b^2 - a^2 - b^2
            //     = 2ab <==> 16 * ab / 8 ==> t^2 / 8
            // ans = t^2*0.125
            ans = a * a * PI * 0.125;

            
        }
        else
        {
            // R*R*PI
            double gray = ((a + b) * (a + b) * PI);
            double wite = (a * a * PI + b * b * PI);
            ans = gray - wite;
           
            //cout << gray << " " << wite << endl;

        }
        printf("%.4f\n", ans);
    }


    return 0;
}
