/* Selection Sort
將每張撲克牌攤開，從這些排中找出最小值放到手中，接著從剩下牌中選擇最小的牌放到手中，直到所有撲克牌全部放到手中。
        [0]  [1]  [2]  [3]  [4]  [5]   min
begin    l    k    j    o    a    b
1        a    k    j    o    l    b    [4]   [0]&[4]交換
2        a    b    j    o    l    k    [5]   [1]&[5]交換   
3        a    b    j    o    l    k    [2]   [2]&[2]交換   
4        a    b    j    k    l    o    [5]   [3]&[5]交換   
5        a    b    j    k    l    o    [4]   [4]&[4]交換   
走訪一次結果
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20

void selectSort(char* data, int length)
{
  int i, j, pos; 
  char temp;

  for(i = 0; i < length; i++)
  {
    //先儲存陣列第一個資料為最小
    //每次執行後第一個資料確認完成
    pos = i;
    temp = data[pos];
    //找出最小值，從排序完成的下一個資料所以i+1
    for(j = i+1;j < length;j++)
    {
      if(data[j] < data[pos])
      {
        pos = j;
        temp = data[j];
      }
    }
    data[pos] = data[i];
    data[i] = temp;
    printf("%d : [%s]\n",i+1, data);
  }
}

int main(void) {
  char data[MAX_LEN] = "lkjoab";
  int len;

  len = strlen(data);
  selectSort(data, len);
  printf("排序結果[%s]\n",data);
  return 0;
}