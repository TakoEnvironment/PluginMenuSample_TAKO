#include "cheats.h"
#include <stdbool.h>
#include <stdio.h>
#include "hid.h"

/**ここから下を追加してください(ここより上の部分には何が書かれてるかわかりませんが、#define SPEED ... とかは消さないで残しておいてください**/
#include "values.h"
#define YOKAI 62
#define ADDRESS 0x08758FA0
#define JUMP 0xCC
#define NEW3DS 0x03C00000 //←これはNEW3DSの場合は 0x03C00000 に。OLD3DSの場合は 0x00000000 にしてね！(NEW3ds → #define NEW3DS 0x03C00000 : OLD3ds → #define NEW3DS 0x00000000
/**↑これらを事前に追加しておいてください**/

/*ボス妖怪作成のソース*/
void	CreateBoss(void)
{
  const static u32 offset = ADDRESS + NEW3DS;
	static u32 backup[YOKAI] = {0};
	if(is_pressed(L))
	{
		if(is_pressed(DU))
		{
			for(int i=0;i<YOKAI;i++)
			{
				if(READU32(offset + (i * JUMP)) != BOSS[i])
				{
					backup[i] = READU32(offset + (i * JUMP));
					WRITEU32(offset + (i * JUMP), BOSS[i]);
				}
			}
		}
		if(is_pressed(DD))
		{
			for(int i=0;i<YOKAI;i++)
			{
				if(backup[i] != 0)
				{
					WRITEU32(offset + (i *JUMP),backup[i]);
				}
			}
		}
	}
}
