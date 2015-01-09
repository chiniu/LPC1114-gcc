#ifndef __UG25664_H__
#define __UG25664_H__

void Initial_ssd1325(void);
void Write_Register(unsigned char cmdData);
void Write_Parameter(unsigned char Data);

void Set_Column_Address(unsigned char a, unsigned char b);
void Set_Row_Address(unsigned char a, unsigned char b);
void ClearLED(unsigned char color);
//void Fill(void);

void Delay(unsigned int Data);

#endif

