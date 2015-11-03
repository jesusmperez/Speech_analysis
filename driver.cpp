// Jesus Perez
// Kristiine Laranjo
// Samba Diallo
// Dario Molina

//******************************************
/*
    A. comparison.txt
    B. The values that match the data file most closely is the Variance and the Mean.
    C. THe value from the data file that is the most diffrent is the average magnitude.
    D. Other statistical measures that would fit this particular project would be the measurements
    of wave length and phonemes, these are the lego blocks that all words are made from
    E. It can be determined that the recordings are very similar because there is only slight diffrences.
*/  


//******************************************



#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
double mean(vector<double>v);
/*[
Precondition:  We put in a vector as an argument
Postcondition:We get the average of vector
Summary: we use this average for other purposes in our code
]*/

double var(vector<double> v);
/*{
Precondition: We put in a vector as an argument
Postcondition: We get the variance of vector
Summary:  We reserve this value to find std. Deviation
]*/

double stdDev(vector<double> v);
/*[
Precondition:  We put in a vector as an argument
Postcondition:  We get square root variance 
Summary: We pass in variance and square root it in function
]*/

double power(vector<double> vec);
/*[
Precondition:  We put in a vector as an argument
Postcondition:  Sum up the values of vectors once they are squared
Summary: USe this values for other purposes in program
]*/

double magnitude(vector<double> vec);
/*[
Precondition:  We put in a vector as an argument
Postcondition:  Find the absolute value of each of the values of the vector
Summary:   Use this value for other purposes in program.
]*/

int crossZero( vector <double> v);
/*[
Precondition:  We put in a vector as an argument
Postcondtion:  Find when values in vector go from postive to negative and vice versa.
Summary:  Keep count how many times this happens

]*/

double statisticalMeasurement(double val, double val2);


int main()
{
    vector<double> name;
    vector<double>name2;
   
    double num, num2;
    double a,b,c,d,e,f;
    double g,h,i,j,k,l;
    
    ifstream fin, fin2;
    ofstream fout;
    fout.open("comparisontxt");
    fin.open("two_a.txt");
    fin2.open("two_b.txt");
    
    while(fin >> num)
    {
       name.push_back(num);
        
    }
    cout << setw(15) <<"The mean of [two_a.txt] is: "<< setw(10) << mean(name) << endl;
    a = mean(name);
    b = var(name);
    c = stdDev(name);
    d = power(name);
    e = magnitude(name);
    crossZero(name);
    
    cout <<"The Average power was: "<< power(name) << endl;
     cout <<"The Average magnitude was: "<< magnitude(name) << endl;
     cout <<"The Cross zeros where :" << crossZero(name) << endl;
    
   
    
    fin.close();
    
    
    while(fin2 >> num2)
    {
       name2.push_back(num2);
        
    }
    cout << setw(25) << "The mean of [two_b.txt] is: "<< setw(7) << mean(name2) << endl;
    f = mean(name2);
    g = var(name2);
    h = stdDev(name2);
    i = power(name2);
    j = magnitude(name2);
    crossZero(name2);
    
     cout <<"The Average power was: "<< power(name2) << endl;
     cout <<"The Average magnitude was: "<< magnitude(name2) << endl;
     cout <<"The Cross zeros where :" << crossZero(name2) << endl;
    
    fin2.close();
    cout.setf(ios::left);
    fout <<setw(20)<< "Comparing : "<< setw(20)<<"two_a.txt"<< setw(20) << "two_b.txt" << setw(20)<< "% Difference" <<setw(20) << endl;
    
    fout << "MEAN : "<< setw(20)<< a << setw(20) << f << setw(20)<< statisticalMeasurement(a, f)<< setw(20) << endl;
    fout << "STANDARD DEV: "<< setw(20)<< b << setw(20) << g << setw(20)<< statisticalMeasurement(b, g)<< setw(20) << endl;
    fout << "VARIANCE: "<< setw(20)<< c << setw(20) << h << setw(20)<< statisticalMeasurement(c, h)<< setw(20) << endl;
    fout << "AVERAGE POWER: "<< setw(20)<< d << setw(20) << i << setw(20)<< statisticalMeasurement(d, i)<< setw(20) << endl;
    fout << "AVERAGE MAGNITUDE: "<< setw(20)<< e << setw(20) << j << setw(20)<< statisticalMeasurement(e, j)<< setw(20) << endl;
    fout.close();
    
}
double mean(vector<double>v)
{
    double result;
    double sum = 0, mean = 0;
    
    double size = v.size();
    
    
    
    for(int i = 0; i< size; i++)
    {
  
        sum = sum + v[i];
    }
  mean = (sum/size);   
    return mean;
}
double var(vector<double> v)
{
    double sum = 0, numElements, variance, mean1;
    mean1= mean(v);
    numElements = v.size();
    for(int i = 0; i < v.size(); i++)
    {
        sum += pow(v[i] - mean1, 2);
    }
    
    variance = sum / numElements;
    cout << "The variance is: " << variance << endl;
    
    return variance;
}
double stdDev(vector<double> v)
{
    double standardDeviation;
    standardDeviation = sqrt(var(v));
    
    cout << "The standard deviation is: " << standardDeviation << endl;
    return standardDeviation;
}
double power(vector<double> vec){
    double sum = 0, total = 0, y;
    int num_val = vec.size();
    
    for(int loop = 0; loop < num_val; loop++){
        sum += pow(vec[loop], 2);
        }
    y = sum / num_val;
    return y;
    }
double magnitude(vector<double> vec){
    double sum = 0, total = 0, y;
    int num_val = vec.size();
    
    for(int loop = 0; loop < num_val; loop++){
        sum += fabs(vec[loop]);
        }
    y =  sum / num_val;
        
    return y;
    }
int crossZero( vector <double> v)
{
  int count = 0;
  for( int i = 0; i < v.size(); i++)
  {
     if( v[i] > 0 && v[i + 1] < 0)
     {
       count++;
     
     } 
     
     else if( v[i] < 0 && v[ i + 1] > 0)
     {
       count++;
     
     }
     
     else if((v[i] > 0) && (v[i+1] == ' '))
     {
       break;
     }
  
    else if( (v[i] < 0) && (v[i+1] == ' '))
     {
       break;
     }
  }

  return count;
}
double statisticalMeasurement(double val, double val2)
{
    double girl = val, robbers = val2;
    double difference;
    const double TWO = 2;
    
    difference = ((girl-robbers)/((girl+ robbers)/TWO))*100;
  
    return fabs(difference);
    
}







