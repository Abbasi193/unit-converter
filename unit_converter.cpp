//this program will convert units of 12 different quantities
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<ctype.h>

using namespace std;

void common(int);
void print(int);
double funcSelect(int,int);
double lengthSi(int);
double energySi(int);
double massSi(int);
double areaSi(int);
double timeSi(int);
double speedSi(int);
void temperature();
double angleSi(int);
double pressureSi(int);
double dataSi(int);
double powerSi(int);
double volumeSi(int);

string name="";

int main()
{	char lcv='A';
	int select;
	while(toupper(lcv)!='N')
	{	cout<<"    **** UNIT CONVERTER ****"<<endl;
		cout<<"Please select physical quantity (1-12)"<<endl;
		cout<<"1. Length\n2. Energy\n3. Mass\n4. Area\n5. Time\n";
		cout<<"6. Speed\n7. Temperature\n8. Angle\n9. Pressure\n";
		cout<<"10.Data\n11.Power\n12.Volume\n";
		cin>>select;
		system("cls");
		switch(select)
		{	case 1:common(select);break;
			case 2:common(select);break;
			case 3:common(select);break;
			case 4:common(select);break;
			case 5:common(select);break;
			case 6:common(select);break;
			case 7:temperature();break;
			case 8:common(select);break;
			case 9:common(select);break;
			case 10:common(select);break;
			case 11:common(select);break;
			case 12:common(select);break;
			default:cout<<"Invalid Input"<<endl;break;

		}
		cout<<"\nDo you want to continue (Y / N)"<<endl;
		cin>>lcv;
		system("cls");
	}
	return 0;
}

void common(int select)
{	double value,preValue;
	string preName;
	int unit;
	
	cout<<"Convert From Unit";
	print(select);//prints names of respective units
	cin>>unit;

	cout<<"Enter Value :";	
	cin>>value;	
	preValue=value;
	value=value*(funcSelect(unit,select));//converts value to multiple of respective si unit
	preName=name;
	
	cout<<"Convert To Unit";
	print(select);
	cin>>unit;
	value=value/(funcSelect(unit,select));//converts unit from si to required unit
	cout<<preValue<<" "<<preName<<" is equivalent to "<<value<<" "<<name<<endl;

}


void print(int select)//prints units according to list of units(select) 
{
	switch(select)
	{case 1:cout<<"(1-9)\n1. KM\n2. Mile\n3. Inch\n4. Foot\n5. Yard\n";
		cout<<"6. Nautical Mile\n7. Meter\n8. Millimeter\n9. Centimeter\n";break;
		
	 case 2:cout<<"(1-8)\n1. Electron Volt\n2. Joules\n3. Kilo Joules\n";
		 cout<<"4. Thermal Kilo Joule\n5. Food Calorie\n6. Foot Pounds\n";
		 cout<<"7. British Thermal Unit\n8. Mega Joule\n";break;
	 
	 case 3:cout<<"(1-8)\n1. Carat\n2. Milligram\n3. gram\n4. Kilogram\n";
	 	cout<<"5. Metric tonne\n6. Ounce\n7. Pounds\n8. Stone\n";break;
	 
	 case 4:cout<<"(1-10)\n1. Square Millimeter\n2. Square Centimeter\n3. Square meter\n";
	 	cout<<"4. Hectare\n5. Square kilometer\n6. Square inch\n";
		cout<<"7. Square feet\n8. Square yard\n9. Acre\n10.Square Mile\n";break;
	 
	 case 5:cout<<"(1-8)\n1. Microsecond\n2. Millisecond\n3. Second\n4. Minute\n";
	 	cout<<"5. Hour\n6. Day\n7. Week\n8. Year\n";break;
	 
	 case 6:cout<<"(1-7)\n1. Centimeter / second\n2. meter / second\n3. Kilometer / hour\n";
	 	cout<<"4. Feet / second\n5. Miles / Hour\n6. Knot\n7. Mach\n";break;
	 
	 case 8:cout<<"(1-3)\n1. Degrees\n2. Radians\n3. Gradians\n";break;
	 
	 case 9:cout<<"(1-6)\n1. Atmosphere\n2. Bars\n3. Kilopascal\n4. mmHg/torr\n5. Pascal\n6. PSI\n";break;
	 
	 case 10:cout<<"(1-10)\n1. Bit\n2. Nibble\n3. Byte\n4. Kilobit\n5. Kilobyte\n";
	 	cout<<"6. Megabit\n7. Megabyte\n8. Gigabyte\n9. Terabyte\n10.Petabyte\n";break;
	 
	 case 11:cout<<"(1-5)\n1. Watt\n2. Kilowatt\n3. Horsepower\n4. Foot-pounds/min\n5. Btu / min\n";break;
	 
	 case 12:cout<<"(1-9)\n1. Millimeter|Cubiccentimeter\n2. Liter\n3. Cubicmeter\n";
	 	cout<<"4. Pint\n5. Quarts\n6. Gallon\n7. Cubic inch\n8. Cubic feet\n9. Cubic yard\n";break;
 
	} 
}
	
double funcSelect(int unit,int select)
{//choose function
//recieve and returns si multiples according to units and quantities(select)
	switch(select)
	{	case 1:return lengthSi(unit);break;
		case 2:return energySi(unit);break;
		case 3:return massSi(unit);break;
		case 4:return areaSi(unit);break;
		case 5:return timeSi(unit);break;
		case 6:return speedSi(unit);break;
		case 8:return angleSi(unit);break;
		case 9:return pressureSi(unit);break;
		case 10:return dataSi(unit);break;
		case 11:return powerSi(unit);break;
		case 12:return volumeSi(unit);break;				
	}
}

double lengthSi(int unit)
{	double multiple;
	switch(unit)//si unit meter w.r.t. other units
	{	case 1:multiple=1000;name="KM";break;
		case 2:multiple=1609.344;name="Mile";break;
		case 3:multiple=0.0254;name="Inch";break;
		case 4:multiple=0.3048;name="Foot";break;
		case 5:multiple=0.9144;name="Yard";break;
		case 6:multiple=1852;name="Nautical Mile";break;
		case 7:multiple=1;name="Meter";break;
		case 8:multiple=0.001;name="Millimeter";break;
		case 9:multiple=0.01;name="Centimeter";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}



double energySi(int unit)
{	double multiple;
	switch(unit)//si unit  joule w.r.t. other units
	{	case 1:multiple=1.602177e-19;name="Electron Volt";break;
		case 2:multiple=1;name="Joules";break;
		case 3:multiple=1000;name="Kilo Joules";break;
		case 4:multiple=4.184;name="Thermal Kilo Joule";break;
		case 5:multiple=4184;name="Food Calorie";break;
		case 6:multiple=1.355818;name="Foot Pounds";break;
		case 7:multiple=1055.056;name="British Thermal Unit";break;
		case 8:multiple=1000000;name="Mega Joule";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}


double massSi(int unit)
{	double multiple;
	switch(unit)//si unit kg w.r.t. other units
	{	case 1:multiple=0.0002;name="Carat";break;
		case 2:multiple=0.000001;name="Milligram";break;
		case 3:multiple=0.001;name="gram";break;
		case 4:multiple=1;name="Kilogram";break;
		case 5:multiple=1000;name="Metric tonne";break;
		case 6:multiple=0.02835;name="Ounce";break;
		case 7:multiple=0.453592;name="Pounds";break;
		case 8:multiple=6.350293;name="Stone";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}


double areaSi(int unit)
{	double multiple;
	switch(unit)//si unit sqmeter w.r.t. other units
	{	case 1:multiple=0.000001;name="Square Millimeter";break;
		case 2:multiple=0.0001;name="Square Centimeter";break;
		case 3:multiple=1;name="Square meter";break;
		case 4:multiple=10000;name="Hectare";break;
		case 5:multiple=1000000;name="Square kilometer";break;
		case 6:multiple=0.000645;name="Square inch";break;
		case 7:multiple=0.092903;name="Square feet";break;
		case 8:multiple=0.836127;name="Square yard";break;
		case 9:multiple=4046.856;name="Acre";break;
		case 10:multiple=2589988;name="Square mile";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}


double timeSi(int unit)
{	double multiple;
	switch(unit)//si unit second w.r.t. other units
	{	case 1:multiple=0.000001;name="Microsecond";break;
		case 2:multiple=0.001;name="Millisecond";break;
		case 3:multiple=1;name="Second";break;
		case 4:multiple=60;name="Minute";break;
		case 5:multiple=3600;name="Hour";break;
		case 6:multiple=86400;name="Day";break;
		case 7:multiple=604800;name="Week";break;
		case 8:multiple=31557600;name="Year";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}


double speedSi(int unit)
{	double multiple;
	switch(unit)//si unit meter/sec w.r.t. other units
	{	case 1:multiple=0.01;name="Centimeter / second";break;
		case 2:multiple=1;name="meter / second";break;
		case 3:multiple=0.277778;name="Kilometer / hour";break;
		case 4:multiple=0.3048;name="Feet / second";break;
		case 5:multiple=0.447;name="Miles / Hour";break;
		case 6:multiple=0.5144;name="Knot";break;
		case 7:multiple=340.3;name="Mach";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}

void temperature()
{ 	double value,preValue;
	string preName;
	int unit;
	
	cout<<"Convert From Unit (1-3)"<<endl;
	cout<<"1. Celsius\n2. Fahrenheit\n3. Kelvin\n";
	cin>>unit;
	
	cout<<"Enter Value :";	
	cin>>value;	
	preValue=value;	
	switch(unit)
	{	case 1:value=value;name="Celsius";break;
	 	case 2:value=(value-32)/1.8;name="Fahrenheit";break;
	 	case 3:value=value-273.1;name="Kelvin";break;
	}
	preName=name;
	
	cout<<"Convert To Unit (1-3)"<<endl;
	cout<<"1. Celsius\n2. Fahrenheit\n3. Kelvin\n";
	cin>>unit;
	cout<<preValue<<" "<<preName<<" is equivalent to ";
	switch(unit)
	{	case 1:cout<<value<<" Celsius"<<endl;break;
	 	case 2:cout<<1.8*value+32<<" Fahrenheit"<<endl;break;	
   		case 3:cout<<value+273.15<<" Kelvin"<<endl;break;
   	default:break;
	}
	
}


double angleSi(int unit)
{	double multiple;
	switch(unit)//si unit radian w.r.t. other units
	{	case 1:multiple=0.017453;name="Degrees";break;
		case 2:multiple=1;name="Radians";break;
		case 3:multiple=0.015708;name="Gradians";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}


double pressureSi(int unit)
{double multiple;
	switch(unit)//si unit pascal w.r.t. other units
	{	case 1:multiple=101325;name="Atmosphere";break;
		case 2:multiple=100000;name="Bars";break;
		case 3:multiple=1000;name="Kilopascal";break;
		case 4:multiple=133.3;name="mmHg/torr";break;
		case 5:multiple=1;name="Pascal";break;
		case 6:multiple=6894.757;name="PSI";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}


double dataSi(int unit)
{	double multiple;
	switch(unit)//byte  w.r.t. other units
	{	case 1:multiple=0.125;name="Bit";break;
		case 2:multiple=0.5;name="Nibble";break;
		case 3:multiple=1;name="Byte";break;
		case 4:multiple=128;name="Kilobit";break;		
		case 5:multiple=1024;name="Kilobyte";break;
		case 6:multiple=131072;name="Megabit";break;
		case 7:multiple=1048576;name="Megabyte";break;
		case 8:multiple=1073741824;name="Gigabyte";break;
		case 9:multiple=1099511627776;name="Terabyte";break;
		case 10:multiple=1099511627776*1024;name="Petabyte";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}


double powerSi(int unit)
{	double multiple;
	switch(unit)//si unit watt w.r.t. other units
	{	case 1:multiple=1;name="Watt";break;
		case 2:multiple=1000;name="Kilowatt";break;
		case 3:multiple=745.6999;name="Horsepower";break;
		case 4:multiple=0.022597;name="Foot-pounds/min";break;		
		case 5:multiple=17.58427;name="Btu / min";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}


double volumeSi(int unit)
{double multiple;
	switch(unit)//si unit cubic meter
	{	case 1:multiple=0.000001;name="Millimeter|Cubiccentimeter";break;
		case 2:multiple=0.001;name="Liter";break;
		case 3:multiple=1;name="Cubicmeter";break;
		case 4:multiple=0.000473;name="Pint";break;		
		case 5:multiple=0.000946;name="Quarts";break;
		case 6:multiple=0.003785;name="Gallon";break;
		case 7:multiple=0.000016;name="Cubic inch";break;		
		case 8:multiple=0.028317;name="Cubic feet";break;
		case 9:multiple=0.764555;name="Cubic yard";break;
		default:cout<<"Invalid Input"<<endl;break;
	}
	return multiple;
}
