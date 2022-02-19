#include<stdio.h>
#include<math.h>
#include<windows.h>
#include <stdlib.h>
void Go(SHORT posX, SHORT posY)          // ham thay doi vi tri con tro tren man hinh
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;
	SetConsoleCursorPosition(hStdout, Position);
}
void ShowCur(bool contro)       //  ham an con tro tren man hinh
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = contro;
    SetConsoleCursorInfo(handle, &ConCurInf);
}
void loading()        // ham in ra thanh loanding
{   
    ShowCur(0);
    char a = 177, b = 219;
    printf("\t\t\t\t\t\t\t Loading");
    for (int i=1; i<3;i++)
    {   
    	printf(".");
    	Sleep(200);
    	printf(".");
    	Sleep(200);
    	printf(".");
    	Sleep(200);
    	printf("\b\b\b   \b\b\b");
    	Sleep(200);
	}
	printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    printf("\n\t\t\t\t\t");
    for (int i = 0; i < 41; i++)
	    printf("%c",a);
    printf("\r");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 41; i++)
    {
        printf("%c",b);
        Sleep(20);
    }
    printf("\n");
    Sleep(50);
    ShowCur(1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int ktsonguyen(){                                 // ham kiem tra so
    float x;                                      
    printf("\n\tThuc hien chuc nang so 1 : Kiem tra so nguyen \n\tNhap so can kiem tra: ");
    scanf("%f",&x);
    
    if (x==int(x))                                 //kiem tra so nguyen
       printf("\tSo %.2f la so nguyen ",x); 
    else 
       printf("\tSo %.2f khong phai la so nguyen",x);
    if (x>=2 && x==int(x))                          //kiem tra so nguyen to
    {
     int k=0;                                 
     for (int i=1;i<=x;i++) 
    	if (int(x)%i==0) ++k;
	 if (k==2)
	    printf("\n\tSo %.2f la so nguyen to ",x);
	 else 
	    printf("\n\tSo %.2f khong phai la so nguyen to",x);
    }
    else 
	    printf("\n\tSo %.2f khong phai la so nguyen to",x);
	if (x>=0 && x==int(x))                         // kiem tra so chinh phuong
	{
		if (sqrt(x)==(int)sqrt(x))
		  printf("\n\tSo %.2f la so chinh phuong",x);
		else 
		  printf("\n\tSo %.2f khong phai la so chinh phuong",x);
	}
	else 
	 printf("\n\tSo %.2f khong phai la so chinh phuong",x);
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int uocchung(int a,int b)    // tim uoc chung lon nhat
{   
    int k,m;
    if (a<0 && b<0) {  k=-a; m=-b; }
    else  {  k=a ; m=b;  }
    
    int ucl=1,ntc;
	int max = (k>m) ? k:m;
	for (int i=1;i<=max;i++)
		if (k%i==0 && m%i==0)
			    ucl=(i>ucl) ? i:ucl;
			    
    if (a<0 && b<0) ntc=-ucl;
    else ntc=ucl;
    return ntc;
}
int ubchung()                  //ham tim uoc chung va boi chung
{
	printf("\n\tThuc hien chuc nang so 2 : Tim uoc so chung va boi so chung cua 2 so");
	printf("\n\tNhap so thu nhat : ");
	int a;
	scanf("%d",&a);
	printf("\tNhap so thu hai : ");
	int b;
	scanf("%d",&b);
	printf("\tUoc chung lon nhat la : %d",uocchung(a,b));
	printf("\n\tBoi chung nho nhat la : %d",a*b/uocchung(a,b)); // boi chung nho nhat
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
 int tienkaraoke()                                    //ham tinh tien karaoke
 {
 	printf("\n\t3.Thuc hien chuc nang so 3 : Chuong trinh tinh tien cho quan karaoke ");
 	int s,e;
 	do
	{                                                       // nhap gio trong thoi gian hoat dong
 	printf("\n\tNhap gio bat dau : ");  scanf("%d",&s);
 	printf("\tNhap gio ket thuc: ");  scanf("%d",&e); 
	if ( e<=s || s<0 || e>24 || s >24 || e<0 )  printf("\tGio khong phu hop vui long nhap lai! "); 
	else if ( s<12||s>23 || e<12||e>23)         printf("\tQuan chi hoat dong tu 12 den 23 gio vui long nhap thoi gian thich hop! ");
	} while ( e<=s || s<12 || s>23 || e<12 || e>23); 
	                                
 	int tg=e-s,tien;
 	
 	if (0<tg<=3)
 	    tien=tg*150000;
 	if (tg>3)
 	    tien=150000*3+(tg-3)*(150000*0.7);
 	if (s>=14&&s<=17)
 	    tien=tien*0.9;
 	    
 	printf("\tSo tien can thanh toan la : %d vnd",tien);
 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int tiendien()                                                    // ham tinh tien dien 
{   
    printf("\n\t4.Thuc hien chuc nang so 4 : Tinh tien dien ");
    int max1=50*1678,
	    max2=max1+50*1734,
	    max3=max2+100*2014,
	    max4=max3+100*2536,
	    max5=max4+100*2834,
		cs;
    do{
	printf("\n\tNhap so kWh su dung :  ");
	scanf("%d",&cs);
	if (cs<0)
	 printf("\tGia tri khong phu hop, moi nhap lai!");} while (cs<0);         
	if (cs>=0&&cs<=50)
	 printf("\n\tTien dien la : %d vnd",cs*1678);
	if (cs>50&&cs<=100)
	 printf("\n\tTien dien la : %d vnd",(cs-50)*1734+max1);
	if (cs>100&&cs<=200)
	 printf("\n\tTien dien la : %d vnd",(cs-100)*2014+max2);
	if (cs>200&&cs<=300)
	 printf("\n\tTien dien la : %d vnd",(cs-200)*2536+max3);
	if (cs>300&&cs<=400)
	 printf("\n\tTien dien la : %d vnd",(cs-300)*2834+max4);  
	if (cs>400)
	 printf("\n\tTien dien la : %d vnd",(cs-400)*2927+max5);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int lainganhang()                                            //ham tinh lai suat ngan hang
{
	printf("\n\t5.Thuc hien chuc nang so 5 : Tinh lai suat vay ngan hang vay tra gop ");
	double goc;
	do {
	printf("\n\tNhap so tien can vay (vnd): ");
	scanf("%lf",&goc);
	if (goc<=0) printf("\tSo tien khong dung moi nhap lai!");} while (goc<=0);
	double conlai=goc, tong=0, tra;
	for (int i=1;i<=12;i++)                                        //output
	 {  
	    tra=goc/12+conlai*0.05;
	 	printf("\tKi han %02d phai tra la : %.0lf vnd\n",i,tra);
	 	conlai-=goc/12;
	 	tong+=tra;
	 }
	printf("\tTong so tien phai tra la : %.0lf vnd",tong);
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
struct sinhvien
{                      
    char hoten[30];
    float diem;
}; 
void nhapttsv(sinhvien sv[100],int n)                //input
{
	for (int i=1;i<=n;i++)
     {  
	    fflush(stdin);
     	printf("\tNhap ho va ten sinh vien thu %d: ",i);
     	gets(sv[i].hoten);
     	do
		{
     	printf("\tNhap diem cua sinh vien thu %d: ",i);
     	scanf("%f",&sv[i].diem);if (sv[i].diem<0||sv[i].diem>10) printf("\tDiem sai moi nhap lai!\n");
		} while (sv[i].diem<0||sv[i].diem>10);
	 }
}
void xuatttsv(sinhvien sv[100],int n)
{
	 for (int i=1;i<=n;i++)
	 {
	 	printf("\t----------------------------");              //output
        printf("\n\tHo va ten : %s ",sv[i].hoten);
        printf("\n\tDiem : %.1f ",sv[i].diem);
        if (sv[i].diem>=9)
        printf("\n\tHoc luc : Xuat sac\n");
        if (sv[i].diem>=8&&sv[i].diem<9)
        printf("\n\tHoc luc : Gioi \n");
        if (sv[i].diem>=6.5&&sv[i].diem<8)
        printf("\n\tHoc luc : Kha \n");
        if (sv[i].diem>=5&&sv[i].diem<6.5)
        printf("\n\tHoc luc : Trung binh\n");
        if (sv[i].diem>=0&&sv[i].diem<5)
        printf("\n\tHoc luc : Yeu\n");
        if (i==n) printf("\t----------------------------");
	 } 
}
int thongtin()                                             //ham thong tin sinh vien
{   
    printf("\n\t6.Thuc hien chuc nang so 6 : Sap xep thong tin sinh vien ");
    struct sinhvien sv[100];
    int n;
    printf("\n\tNhap so luong sinh vien : ");             // input
    scanf("%d",&n);
    nhapttsv(sv,n);
    
	struct sinhvien tt;                                   // thay doi vi tri cua sinh vien
    for (int i=1; i<=n; i++) 
    for (int j=i+1; j<=n; j++)
    if (sv[j].diem > sv[i].diem)
    {
	 tt = sv[j];
     sv[j] = sv[i];
     sv[i] = tt;
	}
	xuatttsv(sv,n);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
struct ps               // khai bao cau truc
{
	int tu,mau;
}kq;
int tongps(int a , int b , int c , int d)
{
	int k=uocchung((a*d+c*b),(b*d)) ;
	kq.tu=(a*d+c*b)/k;
	kq.mau=(b*d)/k;
}
int hieups(int a,int b,int c,int d)
{
	int k=uocchung((a*d-c*b),(b*d)) ;
	kq.tu=(a*d-c*b)/k;
	kq.mau=(b*d)/k;
}
int tichps(int a,int b,int c,int d)
{
	int k=uocchung((a*c),(d*b)) ;
	kq.tu=(a*c)/k;
	kq.mau=(b*d)/k;
}
int thuongps(int a,int b,int c,int d)
{
	int k=uocchung((a*d),(b*c)) ;
	kq.tu=(a*d)/k;
	kq.mau=(b*c)/k;
}
void ketqua(int a, int b)
{
	if (a==0) printf("0");
	else if (b==1) printf("%d",a);
	else printf("%d/%d",a,b);
}
int phanso()                            //ham tinh phan so
{  
	printf("\n\t7.Thuc hien chuc nang so 7 : Tinh toan phan so ");          // input
	struct ps a,b;
    do 
	{
	printf("\n\tNhap phan so thu nhat : ");
	scanf("%d/%d",&a.tu,&a.mau);
	printf("\tNhap phan so thu hai : ");
	scanf("%d/%d",&b.tu,&b.mau);
	if  (a.mau ==0 || b.mau ==0) printf("\tKhong dung dinh dang phan so moi nhap lai!");
    } while (a.mau ==0 || b.mau ==0);
	
	tongps(a.tu,a.mau,b.tu,b.mau);
	printf("\tTong cua 2 phan so %d/%d va %d/%d la : ",a.tu,a.mau,b.tu,b.mau); 
	ketqua(kq.tu,kq.mau) ;
	
	hieups(a.tu,a.mau,b.tu,b.mau);
	printf("\n\tHieu cua 2 phan so %d/%d va %d/%d la : ",a.tu,a.mau,b.tu,b.mau);
	ketqua(kq.tu,kq.mau) ;
	
	tichps(a.tu,a.mau,b.tu,b.mau);
	printf("\n\tTich cua 2 phan so %d/%d va %d/%d la : ",a.tu,a.mau,b.tu,b.mau);
	ketqua(kq.tu,kq.mau) ;
	
	thuongps(a.tu,a.mau,b.tu,b.mau);
	printf("\n\tThuong cua 2 phan so %d/%d va %d/%d la : ",a.tu,a.mau,b.tu,b.mau);
	ketqua(kq.tu,kq.mau) ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void luachon()                                               //ham de chon chuc nang
{
	HANDLE color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n\t[ Nhap lua chon cua ban ] : ");
	int nhap;
	scanf("%d",&nhap); 
	switch (nhap)
	{
		case 1:
			SetConsoleTextAttribute(color,01 );
			loading();
			ktsonguyen();
			break;
		case 2:
			SetConsoleTextAttribute(color,02 );
			loading();
			ubchung();
			break;
		case 3:
			SetConsoleTextAttribute(color,03 );
			loading();
			tienkaraoke();
			break;
		case 4:
			SetConsoleTextAttribute(color,04 );
			loading();
			tiendien();
			break;
		case 5:
			SetConsoleTextAttribute(color,05 );
			loading();
			lainganhang();
			break;
		case 6:
			SetConsoleTextAttribute(color,06 );
			loading();
			thongtin();
			break;
		case 7:
			SetConsoleTextAttribute(color,07 );
			loading();
			phanso();
			break;
		default : 
	    SetConsoleTextAttribute(color,07 );
		printf("\n\tKhong co lua chon cua ban !!!");
	}
	SetConsoleTextAttribute(color,07 );
	printf("\n\n\tNhap [ x ] de thoat khoi chuong trinh hoac nhap phim bat ki de tiep tuc : ");
	fflush(stdin);
	char tieptuc;
	scanf("%c",&tieptuc);
	if (tieptuc!='x')
	{
	  printf("\n\t____________________________________________________________________________________________________");
	  luachon();
    }
}
void mau(){
Sleep(200);
	system ( "color 01");
	Sleep(100);
	system ( "color 02");
	Sleep(100);
	system ( "color 03");
	Sleep(100);
	system ( "color 04");
	Sleep(100);
	system ( "color 05");
	Sleep(100);
	system ( "color 06");
	Sleep(100);
	system ( "color 08");
	Sleep(100);
	system ( "color 07");
	Sleep(100);}
void menu()
{   
    HANDLE color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color,07 );	
	ShowCur(0);
    printf("\n\n"); printf("\t");
	for (int i=1;i<=101;i++)
		printf("%c",static_cast<char>(219));
	printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else if (i==4||i==16||i==20||i==8||i==12||i==24||i==28||i==32||i==36||i==98||i==94||i==90||i==86||i==82||i==78||i==74||i==70||i==66)
	   {
	   	 SetConsoleTextAttribute(color,04 );
	   	 printf("%c",static_cast<char>(286));
	   	 SetConsoleTextAttribute(color,07 );
	   } 
	   else printf(" ");
    }
    printf("\n\t");
    for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else if (i==6||i==14||i==22||i==30||i==38||i==96||i==72||i==88||i==80||i==64)
	   {
	   	SetConsoleTextAttribute(color,02 );
	   	printf("%c",static_cast<char>(254));
	   	SetConsoleTextAttribute(color,07 );
	   }
	   else if (i==49) printf("M");else if (i==50) printf("E");else if (i==51) printf("N");else if (i==52) printf("U");
	   else if(i==10) printf("%c",static_cast<char>(3));
	   else if(i==18) printf("%c",static_cast<char>(5));
	   else if(i==26) printf("%c",static_cast<char>(6));
	   else if(i==34) printf("%c",static_cast<char>(4));
	   else if(i==92) printf("%c",static_cast<char>(3));
	   else if(i==84) printf("%c",static_cast<char>(5));
	   else if(i==76) printf("%c",static_cast<char>(6));
	   else if(i==68) printf("%c",static_cast<char>(4));
	   else printf(" ");
    }
    printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else if (i==4||i==16||i==20||i==8||i==12||i==24||i==28||i==32||i==36||i==98||i==94||i==90||i==86||i==82||i==78||i==74||i==70||i==66)
	   {
	   	 SetConsoleTextAttribute(color,06 );
	   	 printf("%c",static_cast<char>(287));
	   	 SetConsoleTextAttribute(color,07 );
	   } 
	   else printf(" ");
    }
    printf("\n\t");
    for (int i=1;i<=101;i++)
	printf("%c",219);
	printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t%c\t        ",219);
    for (int i=1;i<=21;i++)
    {
    	if (i%2!=0)
		{
		SetConsoleTextAttribute(color,03 );
    	printf("%c",static_cast<char>(223));
    	SetConsoleTextAttribute(color,07 );	
		}
		else
		{
		SetConsoleTextAttribute(color,05 );
    	printf("%c",static_cast<char>(220));
    	SetConsoleTextAttribute(color,07 );	
		}
	}
	printf("     [ CAC CHUC NANG ]     ")  ;
	for (int i=1;i<=21;i++)
    {
    	if (i%2!=0)
		{
		SetConsoleTextAttribute(color,03 );
    	printf("%c",static_cast<char>(223));
    	SetConsoleTextAttribute(color,07 );	
		}
		else
		{
		SetConsoleTextAttribute(color,05 );
    	printf("%c",static_cast<char>(220));
    	SetConsoleTextAttribute(color,07 );	
		}
	}
	printf("               ");printf("%c",219);
	printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t%c\t  ",219); SetConsoleTextAttribute(color,01 );printf("%c",static_cast<char>(31));
	printf("  1.Chuc nang so 1 : Kiem tra so nguyen ");printf("%c",static_cast<char>(15));
	SetConsoleTextAttribute(color,07 );
	printf("                                                ");printf("%c",219);
    printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t%c\t  ",219); SetConsoleTextAttribute(color,02 );printf("%c",static_cast<char>(31));
	printf("  2.Chuc nang so 2 : Tim uoc so chung va boi so chung cua 2 so ");
	printf("%c",static_cast<char>(21));SetConsoleTextAttribute(color,07 );
	printf("                         ");printf("%c",219);
    printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t%c\t  ",219); SetConsoleTextAttribute(color,03 );printf("%c",static_cast<char>(31));
	printf("  3.Chuc nang so 3 : Chuong trinh tinh tien cho quan karaoke ");
	printf("%c",static_cast<char>(14));SetConsoleTextAttribute(color,07 );
	printf("                           ");printf("%c",219);
    printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t%c\t  ",219); SetConsoleTextAttribute(color,04 );printf("%c",static_cast<char>(31));
	printf("  4.Chuc nang so 4 : Tinh tien dien ");printf("%c",static_cast<char>(157));
	SetConsoleTextAttribute(color,07 );
	printf("                                                    ");printf("%c",219);
    printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t%c\t  ",219); SetConsoleTextAttribute(color,05 );printf("%c",static_cast<char>(31));
	printf("  5.Chuc nang so 5 : Tinh lai suat vay ngan hang vay tra gop ");
	printf("%c",static_cast<char>(36));SetConsoleTextAttribute(color,07 );
	printf("                           ");printf("%c",219);
    printf("\n\t"); 
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t%c\t  ",219); SetConsoleTextAttribute(color,06 );printf("%c",static_cast<char>(31));
	printf("  6.Chuc nang so 6 : Sap xep thong tin sinh vien ");printf("%c",static_cast<char>(127));
	SetConsoleTextAttribute(color,07 );
	printf("                                       ");printf("%c",219);
    printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t%c\t  ",219); SetConsoleTextAttribute(color,07 );printf("%c",static_cast<char>(31));
	printf("  7.Chuc nang so 7 : Tinh toan phan so ");printf("%c",static_cast<char>(195));
	SetConsoleTextAttribute(color,07 );
	printf("                                                 ");printf("%c",219);
    printf("\n\t"); 
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t");
	for (int i=1;i<=101;i++)
	{
	   if (i==1||i==101) printf("%c",219);
	   else printf(" ");
    }
    printf("\n\t");
    for (int i=1;i<=101;i++)
	printf("%c",219);
	ShowCur(1);
}
int main()                                                  //ham xu li chinh
{   	
    menu();
    mau();
	Go(0,0);
	menu();
    luachon();
	printf("\n\n\t******************************************** Ket thuc **********************************************");
}

