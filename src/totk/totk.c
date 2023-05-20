/*
 * Pokémon Sword/Shield automation
 */

#include <../util/delay.h>

#include "automation-utils.h"
#include "user-io.h"

/* Static functions */
static void temporary_control(void);
static void two_bow_dupe(void);
// static void max_raid_menu(void);
// static void max_raid_setup(void);
// static void light_pillar_setup_with_control(void);
// static void repeat_change_raid(void);
// static void repeat_change_raid_initial_confirm(void);
// static void light_pillar_setup(void);
// static void set_text_speed(bool fast_speed, bool save);
// static void use_wishing_piece_and_pause(void);
// static void restart_game(void);
// static void change_raid(void);
// static void auto_breeding(void);
// static void reposition_player(bool first_time);
// static void go_to_nursery_helper(void);
// static void get_egg(void);
// static void move_in_circles(uint16_t cycles, bool go_up_first);
// static bool hatch_egg(void);
// static void release_full_boxes(void);
// static void scan_boxes(void);
// static void position_box_cursor_topleft(void);
// static bool for_each_box_pos(bool top_left_start, bool (*callback)(void));
// static bool release_from_box(void);
static bool check_button_press(void);


int main(void)
{
	init_automation();
	init_led_button();

	/* Initial beep to confirm that the buzzer works */
	beep();
	_delay_ms(100);
	beep();
	_delay_ms(100);
	beep();
	_delay_ms(100);
	beep();

	/* Wait for the user to press the button (should be on the Switch main menu) */
	count_button_presses(100, 100);

	/* Set the virtual controller as controller 1 */
	switch_controller(REAL_TO_VIRT);

	for (;;) {
		/* Set the LEDs, and make sure automation is paused while in the
		   menu */
		set_leds(BOTH_LEDS);
		pause_automation();

		/* Feature selection menu */
		uint8_t count = count_button_presses(100, 900);

		for (uint8_t i = 0 ; i < count ; i += 1) {
			beep();
			_delay_ms(100);
		}

		switch (count) {
			case 1:
				temporary_control();
			break;

			case 2:
				two_bow_dupe();
			break;

			// case 3:
			// 	max_raid_menu();
			// break;

			// case 4:
			// 	auto_breeding();
			// break;

			// case 5:
			// 	release_full_boxes();
			// break;

			// case 6:
			// 	scan_boxes();
			// break;

			default:
				/* Wrong selection */
				delay(100, 200, 1500);
			break;
		}
	}
}


/*
 * Temporary gives back control to the user by performing controller switch.
 */
void temporary_control(void)
{
	set_leds(NO_LEDS);

	/* Allow the user to connect their controller back as controller 1 */
	switch_controller(VIRT_TO_REAL);

	/* Wait for the user to press the button (should be on the Switch main menu) */
	count_button_presses(100, 100);

	/* Set the virtual controller as controller 1 */
	switch_controller(REAL_TO_VIRT);
}

const int LONG_WAIT = 20;
const int SHORT_WAIT = 3;
/*
 * Press A repetitively until the button is pressed.
 */
static void two_bow_dupe(void)
{

	SEND_BUTTON_SEQUENCE(

		{BT_P, DP_NEUTRAL, SEQ_MASH, 1}, //Pause
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, LONG_WAIT}, //Wait
		
		{BT_L, DP_NEUTRAL, SEQ_MASH, 1}, //Go to armor
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_L, DP_NEUTRAL, SEQ_MASH, 1}, //Go to armor
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_L, DP_NEUTRAL, SEQ_MASH, 1}, //Go to armor
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_L, DP_NEUTRAL, SEQ_MASH, 1}, //Go to armor
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_L, DP_NEUTRAL, SEQ_MASH, 1}, //Go to armor
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_L, DP_NEUTRAL, SEQ_MASH, 1}, //Go to armor
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_L, DP_NEUTRAL, SEQ_MASH, 1}, //Go to armor
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_L, DP_NEUTRAL, SEQ_MASH, 1}, //Go to armor
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

		{BT_R, DP_NEUTRAL, SEQ_MASH, 1}, //Go to bows
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

		{BT_NONE, DP_RIGHT, SEQ_MASH, 1}, //Go to Right Bow Slot
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_NONE, DP_RIGHT, SEQ_MASH, 1}, //Go to Right Bow Slot
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_NONE, DP_RIGHT, SEQ_MASH, 1}, //Go to Right Bow Slot
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_NONE, DP_RIGHT, SEQ_MASH, 1}, //Go to Right Bow Slot
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait


		{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //select bow
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //equip/unequip bow
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait


		{BT_NONE, DP_LEFT, SEQ_MASH, 1}, //Go to thrid Bow Slot
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_NONE, DP_LEFT, SEQ_MASH, 1}, //Go to thrid Bow Slot
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		// {BT_NONE, DP_LEFT, SEQ_MASH, 1}, //Go to thrid Bow Slot
		// {BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

		{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //select bow
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //equip bow
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

		
		{BT_NONE, DP_RIGHT, SEQ_MASH, 1}, //Go to Right Bow Slot
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_NONE, DP_RIGHT, SEQ_MASH, 1}, //Go to Right Bow Slot
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		

		{BT_P, DP_NEUTRAL, SEQ_MASH, 1}, //UnPause
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, LONG_WAIT}, //Wait

		{BT_B, DP_NEUTRAL, SEQ_MASH, 1}, //Put weapon away
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		{BT_ZR, DP_NEUTRAL, SEQ_MASH, 1}, //Draw Bow
		{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		
		
	);

	 for (;;) {
	// 		/* Move around in the Box */
			if (check_button_press()) {
				/* The user stopped the operation */
				break;
			}

	// 		// 	/* Uses held A button to makes the text go faster. */
		SEND_BUTTON_SEQUENCE(

			//equip dupe item to bow
			{BT_NONE, DP_TOP, SEQ_MASH, 1}, //Press up DPad
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, LONG_WAIT}, //Wait

			//drop bow and move to next
			{BT_P, DP_NEUTRAL, SEQ_MASH, 1}, //Pause
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, LONG_WAIT}, //Wait

			{BT_NONE, DP_LEFT, SEQ_MASH, 1}, //go left 2
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
			{BT_NONE, DP_LEFT, SEQ_MASH, 1}, //go left 2
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, // select bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_NONE, DP_BOTTOM, SEQ_MASH, 1}, //Go down to drop
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
	

			{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //Drop Bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_NONE, DP_RIGHT, SEQ_MASH, 1}, //go to next bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //select bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //equip bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			//cycle pause
			{BT_P, DP_NEUTRAL, SEQ_MASH, 1}, //unpause, pause
			//{BT_NONE, DP_NEUTRAL, SEQ_HOLD, 1}, //Wait
		);

		_delay_ms(105);

		SEND_BUTTON_SEQUENCE(
			{BT_P, DP_NEUTRAL, SEQ_MASH, 1}, //unpause, pause
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, LONG_WAIT}, //Wait

			//drop second bow and move to next
			{BT_NONE, DP_LEFT, SEQ_MASH, 1}, //go left 1
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, // select bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_NONE, DP_BOTTOM, SEQ_MASH, 1}, //Go down to drop
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //Drop Bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_NONE, DP_RIGHT, SEQ_MASH, 1}, //go to next bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //select bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, //equip bow
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait

			//dupe should be done
			{BT_P, DP_NEUTRAL, SEQ_MASH, 1},//unpause
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, LONG_WAIT}, //Wait
		);

		//turn around
		for(int i=0;i<2;i++){
			send_update(BT_NONE, DP_NEUTRAL, S_BOTTOM, S_NEUTRAL);
		}
		send_update(BT_A, DP_NEUTRAL, S_NEUTRAL, S_NEUTRAL);

		SEND_BUTTON_SEQUENCE(
			//{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
			{BT_A, DP_NEUTRAL, SEQ_MASH, 1}, 
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
			{BT_A, DP_NEUTRAL, SEQ_MASH, 1},
			{BT_NONE, DP_NEUTRAL, SEQ_HOLD, SHORT_WAIT}, //Wait
		);

		for(int i=0;i<2;i++){
			send_update(BT_NONE, DP_NEUTRAL, S_TOP, S_NEUTRAL);
		}

		send_update(BT_A, DP_NEUTRAL, S_NEUTRAL, S_NEUTRAL);

	}

	set_leds(NO_LEDS);
	send_update(BT_NONE, DP_NEUTRAL, S_NEUTRAL, S_NEUTRAL);

	_delay_ms(200);
}

/*
 * Checks if the button is pressed for a short period of time.
 */
bool check_button_press(void)
{
	return delay(0, 0, 20) != 0;
}
