/** ここから上の処理はカットしてます。void my_menus(void) はコピーしてください**/

#define TITLE 0x001C9C00

void	my_menus(void)
{
// この部分にはタイトルが同じ場合でも違う場合でも共通した処理を書きます。(任意)
	if(get_tid_low() == TITLE)
  {
  // この中にゲームタイトルが同じ場合の処理を書きます。( { から } まで)
  // 例：new_entry("Cheat",code_1);
	}
	else
  { 
  // この中にゲームタイトルが違う場合の処理を書きます。( { から } まで)
  // 例：new_unselectable_entry("Your title is wrong!");
	}
// この部分にもタイトルが同じ場合でも違う場合でも共通した処理を書きます。(任意)
}
