
/*

void form0Events(void) {
	if (Form[0].But[4].event.Pressed) // Button 4 pressed event
	{
		Form[0].But[4].event.Pressed = 0;
		Form[G_Status.FormIndex].~FORM();
		G_Status.FormIndex = 1;
		Form[G_Status.FormIndex].InitForm();
	}

	if (Form[0].But[3].event.Pressed) // Button 4 pressed event
	{
		Form[0].But[3].event.Pressed = 0;
		Form[0].FormBackColor = Red;
		Form[0].FillForm();
	}

	if (Form[0].But[2].event.Pressed) // Button 4 pressed event
	{
		Form[0].But[2].event.Pressed = 0;
		Form[0].FormBackColor = Green;
		Form[0].FillForm();
	}

	if (Form[0].But[1].event.Pressed) // Button 4 pressed event
	{
		Form[0].But[1].event.Pressed = 0;
		if (Form[0].But[0].status.Hold == 0)
			Form[0].But[0].status.Hold = 1;
		else
			Form[0].But[0].status.Hold = 0;

	}

	if (Form[0].But[0].event.Pressed) // Button 4 pressed event
	{
		Form[0].But[0].event.Pressed = 0;
		Form[0].FormBackColor = Black;
		Form[0].FillForm();

		Graph->back_color = Form[0].FormBackColor; //initialization of graph variable
		Graph->graph1_color = Green;
		sprintf(Graph->graph1_x_legend, "Frequency(KHz)");
		Graph->graph1_x_max = 200;
		Graph->graph1_x_min = 0;
		sprintf(Graph->graph1_y_legend, "Amplitude(Volt)");
		Graph->graph1_y_max = 3.0f;
		Graph->graph1_y_min = 0.0f;
		Graph->graph2_color = Cyan;
		sprintf(Graph->graph2_x_legend, "Frequency(KHz)");
		Graph->graph2_x_max = 200;
		Graph->graph2_x_min = 0;
		sprintf(Graph->graph2_y_legend, "AMPERES");
		Graph->graph2_y_max = 3.0f;
		Graph->graph2_y_min = 0.0f;
		Graph->grid_color = Red;
		Graph->status.LegendW = 1;
		Graph->x_grid_size = 16;
		Graph->x_grid_width = 16;
		Graph->x_start = 33;
		Graph->x_width = 256;
		Graph->y_grid_size = 20;
		Graph->y_grid_width = 9;
		Graph->y_start = 25;
		Graph->y_width = 180; //initialization of graph variable
		//Graph.fillGraph();

	}

	if (Form[0].But[0].status.RESERVED == 1) {
		Form[0].But[0].status.RESERVED = 0;

		Graph->fillGraph();
		Graph->status.LegendW = 0;

	}
	//Form[G_Status.FormIndex].But[Form[G_Status.FormIndex].ClickedItemNumOld].addButton();

}

void form1Events(void) {

	if (Form[1].But[3].event.Pressed) // Button 4 pressed event
	{
		Form[1].But[3].event.Pressed = 0;
		Form[G_Status.FormIndex].~FORM();
		G_Status.FormIndex = 0;
		Form[G_Status.FormIndex].InitForm();
	}

	if (Form[1].But[2].event.Pressed) // Button 4 pressed event
	{
		Form[1].But[2].event.Pressed = 0;
		Form[1].FormBackColor = Green;
		Form[1].FillForm();
	}

	if (Form[1].But[1].event.Pressed) // Button 4 pressed event
	{
		Form[1].But[1].event.Pressed = 0;
		Form[1].FormBackColor = Grey;
		Form[1].FillForm();
	}

}

*/
