#include "APP_Includes.h"

int main(){
	DIO_voidInit();
	LCD_init();
	KPD_voidInit();
	u8 keyPressed, intNum, i = 0;
	f32 calc,temp1, temp2, temp3;
	LCD_displayString("Welcome To My");
	LCD_GoToXY(1, 0);
	LCD_displayString("Calculator");
	_delay_ms(50);
	LCD_ClearScreen();
	
	while(1){
		KPD_u8GetKeyState(&keyPressed);
		if(keyPressed != KPD_UnPressed){
			if((keyPressed >= '0') && (keyPressed <= '9')){
				LCD_displayCharacter(keyPressed);
				i++;
				intNum = keyPressed - '0';
				
				switch(i){
					case 1:
						temp1 = intNum;
						break;
					case 2:
						temp1=(temp1*10)+intNum;
					    break;
					case 3:
						temp1=(temp1*100)+intNum;
					    break;
					case 4:
						temp1=(temp1*1000)+intNum;
					    break;
				}
			}
			

			
			switch(keyPressed){
				case '*':
					LCD_displayCharacter(keyPressed);
					i = 0;
					temp2 = temp1;
					temp3 = keyPressed;
					break;
				case '+':
					LCD_displayCharacter(keyPressed);
					i = 0;
					temp2=temp1;
					temp3=keyPressed;
				    break;
				case '-':
					LCD_displayCharacter(keyPressed);
					i = 0;
					temp2=temp1;
					temp3=keyPressed;
				    break;
				case '/':
					LCD_displayCharacter(keyPressed);
					i = 0;
					temp2=temp1;
					temp3=keyPressed;
				    break;
				case '=':
					LCD_displayCharacter(keyPressed);
					 i=0;
					  if(temp3 == '*'){
						  calc = temp1 * temp2;
						  LCD_display_WriteNumber(calc); 
						 
					  }
					  
					  if(temp3 == '+'){
						  calc = temp1 + temp2;
						  LCD_display_WriteNumber(calc); 
					  }
					  
					  if(temp3 == '-'){
						  calc = temp2 - temp1;
						  if(temp2 < temp1){
							  displayMinusNumbers(calc);
						  }
						  else{
							  LCD_display_WriteNumber(calc); 
						  }
					  }
					  if(temp3 == '/'){
						  if(temp1 != 0){
							  calc = temp2 / temp1;
							  displayFloatOnLCD(calc);
						  }
						  else{
							  LCD_displayString("Infinity");
						  }
					  }

					  
					  
					  temp1 = 0;
					  temp2 = 0;
					  temp3 = 0;
					   break;
				case 'C':
					  i=0;
					  LCD_ClearScreen();
					break;
			}
		}
	}
	return 0;
}
