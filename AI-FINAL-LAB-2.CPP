#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    double input [2] = {0.05,0.10};
    double input_weigth [4] = {0.15,0.20,0.25,0.30};
    double output_weigth [4] = {0.40,0.45,0.50,0.55};
    double b1=0.35, b2=0.60, o1=0.01, o2=0.99;
    int bias = 1;
    double net_input_1,net_input_2,out_h1,out_h2,net_output_1,net_output_2,output_1,output_2,error_1,error_2,total_error;
    double epc=0.7;
    double total_error_array[10], smallest=10;

    for(int i=0;i<10;i++){
    net_input_1=input[0]*input_weigth[0]+input[1]*input_weigth[1]+bias*b1;
    net_input_2=input[0]*input_weigth[2]+input[1]*input_weigth[3]+bias*b1;

    out_h1=1/(1+pow(2.71828126,-net_input_1));
    out_h2=1/(1+pow(2.71828126,-net_input_2));

    net_output_1=out_h1*output_weigth [0]+out_h2*output_weigth [1]+bias*b2;
    net_output_2=out_h1*output_weigth [2]+out_h2*output_weigth [3]+bias*b2;

    output_1=1/(1+pow(2.71828126,-net_output_1));
    output_2=1/(1+pow(2.71828126,-net_output_2));

    error_1=0.5*pow((o1-output_1),2);
    error_2=0.5*pow((o2-output_2),2);

    total_error=error_1+error_2;

    total_error_array[i]=total_error;

    cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout << "Input 1 for Iteration " << i+1 << " is : " << net_input_1 <<endl;
    cout << "Input 2 for Iteration " << i+1 << " is : " << net_input_2 << endl;
    cout << "Output 1 for Iteration " << i+1 << " is : " << output_1 <<endl;
    cout << "Output 2 for Iteration " << i+1 << " is : " << output_2 << endl;
    cout << "Error 1 for Iteration " << i+1 << " is : " << error_1 <<endl;
    cout << "Error 2 for Iteration " << i+1 << " is : " << error_2 << endl;
    cout << "Total Error for Iteration " << i+1 << " is : " << total_error << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout << endl;
    for(int j=0;j<10;j++){
        input_weigth[j]=input_weigth[j]-epc*total_error;
        output_weigth[j]=output_weigth[j]-epc*total_error;
    }
    }
    //cout << smallest;
    for (int k=0;k<10;k++){
        if (total_error_array[k]<smallest)
            smallest=total_error_array[k];
    }
    cout << "Minimum value among them: " << smallest;
    cout << endl;
}
