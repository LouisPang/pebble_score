#include <main.h>
 
Window* window;
TextLayer *text_layer1;
TextLayer *text_layer2;
TextLayer *score1_layer;
int score1 = 0;
static char textscore1[4];
TextLayer *score2_layer;
int score2 = 0;
static char textscore2[4];
TextLayer *result;
TextLayer *result_layer;
bool gameover=false;
TextLayer *final_score1_layer;
TextLayer *final_score2_layer;
void show_score(){
  final_score1_layer = text_layer_create(GRect(0, 78, 72, 77));
  text_layer_set_text(final_score1_layer,textscore1);
  text_layer_set_font(final_score1_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(final_score1_layer));
  text_layer_set_text_alignment(final_score1_layer, GTextAlignmentCenter);
  final_score2_layer = text_layer_create(GRect(77, 78, 72, 77));
  text_layer_set_text(final_score2_layer,textscore2);
  text_layer_set_font(final_score2_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(final_score2_layer));
  text_layer_set_text_alignment(final_score2_layer, GTextAlignmentCenter);
}
void win(){
  result_layer = text_layer_create(GRect(0, 0, 144, 77));
  text_layer_set_text(result_layer,"You Win");
  text_layer_set_font(result_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(result_layer));
  show_score();
}
void lose(){
  result_layer = text_layer_create(GRect(0, 0, 144, 77));
  text_layer_set_text(result_layer,"You Lose");
  text_layer_set_font(result_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(result_layer));
  show_score();
  
}
 
/* -------------------------------------------------*/
 
void up_click_handler(ClickRecognizerRef recognizer, void *context) 
{
    /* -------------------------------------------------*/
    if (gameover == false){
    score1 ++; //add 1
    snprintf(textscore1, sizeof(textscore1), "%d", score1);
    //APP_LOG(APP_LOG_LEVEL_DEBUG, "team 1 %s", textscore1);
    text_layer_set_text(score1_layer, textscore1);}
    if (score1 >= 21&&(score1-score2 >1)&&gameover == false) {
     APP_LOG(APP_LOG_LEVEL_DEBUG, "team1 win");
     win();
      gameover = true;
    } 
    //APP_LOG(APP_LOG_LEVEL_DEBUG, "team 1 %s", textscore1);
    /* -------------------------------------------------*/
}
void down_click_handler(ClickRecognizerRef recognizer, void *context) 
{
    if (gameover == false){
    score2 ++; //add 1
    snprintf(textscore2, sizeof(textscore2), "%d", score2);
      text_layer_set_text(score2_layer, textscore2);}
     if (score2 >= 21&&(score2-score1 >1)&&gameover == false) {
     APP_LOG(APP_LOG_LEVEL_DEBUG, "team2 win");
     lose();
    gameover = true;
    } 
    //APP_LOG(APP_LOG_LEVEL_DEBUG, "team 2 %s", textscore2);
 
}
 
void select_click_handler(ClickRecognizerRef recognizer, void *context)
{
  if (gameover == true)
    {
    score2=0;score1=0;
    text_layer_destroy(result_layer);
    snprintf(textscore1, sizeof(textscore1), "%d", score1);
    text_layer_set_text(score1_layer, textscore1);
    snprintf(textscore2, sizeof(textscore2), "%d", score2);
    text_layer_set_text(score2_layer, textscore2);
    text_layer_destroy(final_score1_layer);
    text_layer_destroy(final_score2_layer);
    gameover = false;
  } 
   // APP_LOG(APP_LOG_LEVEL_DEBUG, "Select");
}
 
void click_config_provider(void *context) 
{
	window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
	window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
	window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}
 
/* Load all Window sub-elements */
void window_load(Window *window)
{ 
  text_layer1 = text_layer_create(GRect(0, 0, 110, 77));
  text_layer2 = text_layer_create(GRect(0, 77, 110, 154));
  score1_layer = text_layer_create(GRect(110, 0, 144, 77));
  score2_layer = text_layer_create(GRect(110, 78, 144, 154));
	// Set the text, font, and text alignment
  
	text_layer_set_text(text_layer1,"Team 1");
  text_layer_set_text(text_layer2, "Team 2");
	text_layer_set_font(text_layer1, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
	text_layer_set_text_alignment(text_layer1, GTextAlignmentLeft);
  
	text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
	text_layer_set_text_alignment(text_layer2, GTextAlignmentLeft);
	
	// Add the text layer to the window
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer1));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));

  //score text layer
  snprintf(textscore1, sizeof(textscore1), "%d", score1);
  text_layer_set_text(score1_layer, textscore1);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(score1_layer));
  text_layer_set_font(score1_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  snprintf(textscore2, sizeof(textscore2), "%d", score2);
  text_layer_set_text(score2_layer, textscore2);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(score2_layer));
  text_layer_set_font(score2_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));

}
 
/* Un-load all Window sub-elements */
void window_unload(Window *window)
{
    text_layer_destroy(text_layer1);
    text_layer_destroy(text_layer2);
    text_layer_destroy(score1_layer);
    text_layer_destroy(score2_layer);
}
 
/* Initialize the main app elements */
void init()
{
	window = window_create();
	WindowHandlers handlers = {
		.load = window_load,
		.unload = window_unload
	};
	window_set_window_handlers(window, (WindowHandlers) handlers);
	window_set_click_config_provider(window, click_config_provider);
	window_stack_push(window, true);
   APP_LOG(APP_LOG_LEVEL_DEBUG, "in init");
  //score system
  
}
 
/* De-initialize the main app elements */
void deinit()
{
	window_destroy(window);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "deinit");
}
 
/* Main app lifecycle */
int main(void){
  init();
	app_event_loop();
	deinit();
}