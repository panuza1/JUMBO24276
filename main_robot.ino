#include <BMROBOT.h>
//---------------- ฟอร์มสำหรับทำภารกิจ------------------------
        //         -A0 -A1 -A2 -A3 -A4 -A5 -A6 -A7        
int ref_white[8]= {1019,1019,128 ,105, 132, 84, 35, 49 };     //  ใส่ค่าสีขาว   ***  แสงเช้า และบ่าย  ไม่เท่ากัน ***
int ref_black[8]= { 50, 60, 49, 46,90, 48, 14, 19};     //  ใส่ค่าสีดำ
int ref[8];            
//---------------------  เข้าที่ Serial Monitor เพื่อใส่ค่าสีขาว สีดำ จากสนามจริง -----------------
//-------------------  ใส่ค่าสีขาว โดยวางบนพื้นขาว และให้ล้ออยู่บนลูกระนาด(ถ้ามี) -----------------
//--------------------  เนื่องจาก ค่าสีขาวบนลูกระนาด จะมีค่าน้อยกว่าบนพื้นเรียบ ---------------
//----------------------  จะทำให้เวลาขึ้นบนลูกระนาดเซนเซอร์อ่านเป็นสีดำ   ---------------
//======== กำหนดตำแหน่งพอร์ตเซนเซอร์ ===========
int sen_FL = 7;     // ด้านหน้าซ้าย
int sen_FR = 6;     // ด้านหน้าขวา
int sen_FC = 5;     // ด้านหน้ากลาง  เช็คเส้นดำด้านหน้า(กำแพง)
int sen_RL = 3;     // ด้านหลังซ้าย
int sen_RR = 2;     // ด้านหลังขวา
int p=30 ;          // กำลังของมอเตอร์(%)
void setup() {   
  set_robot(); 
  pos_1();      // ชุดส่งกล่อง  เซอร์โวต่อช่อง SV1 (ตำแหน่งเริ่มต้น ใส่กล่องได้ 5 ใบ)
  OK3();
  cal_ref();   // คำนวณค่าอ้างอิงสำหรับเซนเซอร์ทุกตัว
}
void loop() {
//-------  กำหนดฟังก์ชั่นสำหรับทำภารกิจ  ตามลำดับ  --------
    
    motor(26,29); delay(500);
    track_wall(p); turnR(p); 
    setbot_rear(p);

    motor(26,29); delay(300);
    track_wall(p); turnR(p);  //โค้ง 2 ให้หันเยอะหน่อยก็ได้
    setbot_rear(p);

    motor(26,29); delay(200);  
    track_wall(p); 
    setbot_front(p);
    motor(-26,-29); delay(200); //
    
    turnR(p); 
    setbot_rear(p);
    motor(26,29); delay(300);
 
    turnL(p); //ไปจูลด้วย
    setbot_rear(p); // ไปจูลใหม่จัดตรงหน้า drop 1 ต้องตรงเหี้ย_
    motor(26,29); delay(1500);
    track_wall(p);
    setbot_front(p); // จัดหน้า drop 1
    send_BOX();

    motor(-p,-p); delay(600);  // ถอย drop 1 เสร็จไปจูล
    turnL(p); setbot_rear(p);

    
    motor(30,30); delay(1500); //ข้าม ตะเกียบ
    track_wall(p); setbot_front(p);

    motor(-26,-29); delay(500);  //ถอยหลุมดำ
    turnR(p); 
    motor(26,29); delay(300); // _l 
    track_wall(p);

    setbot_front(p);
    motor(-26,-29); delay(200);  
    turnR(p); 
    setbot_rear(p);

    track_wall(p); 
    setbot_front(p);
    send_BOX(); // drop 2

    setbot_rear(p);
    motor(26,29); delay(200);
    turnR(p); //หน้าตรง

    setbot_rear(p);
    motor(26,31); delay(2500); //เนิน
    track_wall(p);

    setbot_front(p); //จัดหน้าบนเนิน
    motor(-26,-29); delay(200); 
    turnR(p); // `เลี้ยวเนิน 

    setbot_rear(p); // จัดหลังเนิน 
    motor(36,39); delay(300);// ลงเนิน 
    track_wall(p);
    setbot_front(p);

    motor(-26,-29); delay(500); 
    turnR(p); 
    setbot_rear(p);

    motor(26,29); delay(1600); // ตรงฃิบหาย
    track_wall(p);
    setbot_front(p);
    motor(-26,-29); delay(300);

    turnR(p); 
    setbot_rear(p);
    track_wall(p); 
    setbot_front(p);
    send_BOX(); // drop 3  

    motor(-26,-29); delay(200);
    setbot_rear(p);

    motor(26,29); delay(300);
    turnR(p);
    setbot_rear(p); // จัดหลัง drop 3 

    motor(26,29); delay(1200); // ตรงเหี้ยๆ
    turnR(p);
    setbot_rear(p);

    motor(26,29); delay(500);
    track_wall(p); 
    setbot_front(p);
    motor(-26,-29); delay(300); 

    turnL(p);
    motor(26,29); delay(400); 
    track_wall(p);

    turnL(p);
    setbot_rear(p);
    motor(26,29); delay(200);
    track_wall(p);

    setbot_front(p);
    send_BOX(); // drop 4 //ฝั่งไกล

    motor(-26,-29); delay(200);
    setbot_rear(p);

    motor(26,29); delay(300);
    turnL(p);
    setbot_rear(p); // จัดหลัง โครตตรง

    motor(26,29); delay(2000); //ทีเด็ด ตรง
    track_wall(p);
    setbot_front(p);

    motor(-26,-29); delay(300);
    turnR(p);
    setbot_rear(p);

    motor(26,29); delay(200);
    track_wall(p);
    setbot_front(p);

    

    

    
    
    


      
     
    

    


    
    

    

    
    

    

    

    

    

    
    
    
    
       

    
    
    
    
    
    
    

    

    

    
     

    
     
    
     
   
    
     

     

     
     
     
  
     


     

     
     


     
    
     

       
  
     


     

     

     
    
    
    

     

     
     

    
     
     
     
     
     
     
     
   
   

    
      ao();  beep(); delay(2000);
      while(1) delay(2000);     //  หยุดหุ่นยนต์
}
//=============================================================================================================
//=============ส่วนฟังก์ชั่นสำหรับใช้งาน=============================================================================
//=============================================================================================================
void track_wall(int p)      //    แทรกเส้นดำด้านข้าง และถอยหลังเมื่อเซนเซอร์ด้านหน้าเจอสีดำ 
{
      while(A_analog(sen_FC)>ref[sen_FC]) track_w(p);    //  เมื่อเซนเซอร์ด้านหน้าเจอสีดำ จะถอยหลัง
      ao();  delay(300); 
      motor(-p,-p);  delay(400);       //  ถอยหลังออกจากเส้นดำ
      ao();  delay(50);  
}
void track_w(int p)       //  แทรกเส้นดำด้านข้าง
{
        int L=A_analog(sen_FL);
        int R=A_analog(sen_FR);
            if( L>ref[sen_FL] && R>ref[sen_FR])
                {
                  motor(22,25);                  
                }
    else    if( L<ref[sen_FL] && R>ref[sen_FR])  
                {  
                  motor(p,-p);  delay(50);       // ดีเลย์สำหรับการหมุน  ปรับเปลี่ยนได้
                  motor(p,p);  delay(5);
                }
    else    if( L>ref[sen_FL] && R<ref[sen_FR])    
                {
                  motor(-p,p); delay(50);        // ดีเลย์สำหรับการหมุน  ปรับเปลี่ยนได้
                  motor(p,p);  delay(5);
                }
}
//---------------ปรับตำแหน่งหุ่นยนต์โดยใช้เซนเซอร์ด้านหน้า-----------------------------
void setbot_front(int p)
{     char di='N';
      motor(22,27);            // เดินตรงเข้าหาเส้น  เพื่อเช็คว่าหุ่นยนต์เอียงไปด้านใด
      while(1)
          {   delay(1);
              if(A_analog(sen_FL)<ref[sen_FL]) di='L'; 
              if(A_analog(sen_FR)<ref[sen_FR]) di='R'; 
              if(di!='N') break;
          }
       motor(-p,-p); delay(50);  ao();        
      if(di=='R')
        {   beep();  delay(250);
            motor(28,-20);    
            while(A_analog(sen_FL)>ref[sen_FL]) delay(5);  //  โอเค
            motor(-p,0); delay(50);
        }
       if(di=='L')
        {   beep();  delay(50);    beep();  delay(250);
            motor(-15,30); //    
            while(A_analog(sen_FR)>ref[sen_FR]) delay(5);
            motor(0,-p); delay(50);
        }      
      ao(); beep();  delay(200);
}
//---------------ปรับตำแหน่งหุ่นยนต์โดยใช้เซนเซอร์ด้านหลัง-------------------
void setbot_rear(int p)
{     p=p-10;
      char di='N';
      motor(-22,-27);          // ถอยหลังเข้าหาเส้นดำ  เพื่อเช็คว่าหุ่นยนต์เอียงไปด้านใด
      while(1)
          {   delay(1);
              if(A_analog(sen_RL)<ref[sen_RL]) di='L'; 
              if(A_analog(sen_RR)<ref[sen_RR]) di='R'; 
              if(di!='N') break;
          }
         motor(p,p); delay(20);  ao();        
      if(di=='R')
        {   beep();  delay(250);
            motor(-31,20);    
            while(A_analog(sen_RL)>ref[sen_RL])   delay(5);
            motor(p,-p); delay(50);
        }
       if(di=='L')
        {   beep();  delay(50);    beep();  delay(250);
            motor(23,-32);    
            while(A_analog(sen_RR)>ref[sen_RR])   delay(5);
            motor(-p,p); delay(50);
        }      
      ao(); beep();  delay(200);
}
//-----------------หมุนตัว 90องศา ด้วย Encoder--------------------
void turnR(int p)    // ฟังก์ชั่นหมุนขวา 90 องศา
{
   motor(32,-26);    delay(400);  // หมุนขวา
}
void turnL(int p)    // ฟังก์ชั่นหมุนซ้าย 90 องศา
{
  motor(-p,30);    delay(400); 
}
//-----------------ชุดส่งกล่อง--------------------
 void send_BOX(void)
 {  pos_1(); 
    pos_2();
 }
void pos_1(void)
{
   servo(1,105);    //  ตำแหน่งเตรียมพร้อมปล่อยกล่อง 
   delay(300);      
}
void pos_2(void)
{
   servo(1,10);    //  ตำแหน่งดันกล่องออกจากช่องเก็บ 
   delay(500);     //  พักกล่องใบถัดไปไว้บนก้านส่งกล่อง 
}

//-----------ฟังก์ชั่นสำหรับคำนวณค่าอ้างอิง ref------------
void cal_ref()
{
    ref[0] = (ref_black[0]+ref_white[0]) / 2 ;
    ref[1] = (ref_black[1]+ref_white[1]) / 2 ;
    ref[2] = (ref_black[2]+ref_white[2]) / 2 ;
    ref[3] = (ref_black[3]+ref_white[3]) / 2 ;
    ref[4] = (ref_black[4]+ref_white[4]) / 2 ;
    ref[5] = (ref_black[5]+ref_white[5]) / 2 ;
    ref[6] = (ref_black[6]+ref_white[6]) / 2 ;
    ref[7] = (ref_black[7]+ref_white[7]) / 2 ;    
}
