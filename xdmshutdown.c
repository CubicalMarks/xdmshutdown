#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <Xm/Xm.h>
#include <Xm/PushB.h>
#include <Xm/RowColumn.h>

#define FONT "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*"

void b_shutdownPushed(Widget, XtPointer, XmPushButtonCallbackStruct *);
void b_rebootPushed(Widget, XtPointer, XmPushButtonCallbackStruct *);
void print_help();

int main(int argc, char **argv)
{
	Display *display;
	Widget top_widget, rowcol, b_shutdown, b_reboot;
	XtAppContext app;
	XmFontList fontlist;

	top_widget = XtVaAppInitialize(&app, "Push", NULL, 0, &argc, argv,
								   NULL, NULL);

	display = XtDisplay(top_widget);
	fontlist = XmFontListCreate(XLoadQueryFont(display, FONT),
								XmSTRING_DEFAULT_CHARSET);
	
	rowcol = XtVaCreateManagedWidget("rowcolumn",
									 xmRowColumnWidgetClass, top_widget,
									 XmNorientation, XmHORIZONTAL,
									 XmNmarginWidth, 0,
									 XmNmarginHeight, 0,
									 XmNspacing, 0, NULL);

	b_shutdown = XtVaCreateManagedWidget("Shutdown",
										 xmPushButtonWidgetClass, rowcol,
										 XmNfontList, fontlist,
										 XmNshadowThickness, 0,
										 XmNhighlightThickness, 0,
										 XmNmarginLeft, 10,
										 XmNmarginRight, 10,
										 XmNbackground, 0x000000,
										 XmNforeground, 0xbebebe,
										 XmNarmColor, 0x404040, NULL);

	b_reboot = XtVaCreateManagedWidget("Reboot",
									   xmPushButtonWidgetClass, rowcol,
									   XmNfontList, fontlist,
									   XmNshadowThickness, 0,
									   XmNhighlightThickness, 0,
									   XmNmarginLeft, 10,
									   XmNmarginRight, 10,
									   XmNbackground, 0x000000,
									   XmNforeground, 0xbebebe,
									   XmNarmColor, 0x404040, NULL);

	XtAddCallback(b_shutdown, XmNactivateCallback, b_shutdownPushed, NULL);
	XtAddCallback(b_reboot, XmNactivateCallback, b_rebootPushed, NULL);

	XtRealizeWidget(top_widget);

	XtAppMainLoop(app);

	return 0;
}

void b_shutdownPushed(Widget w, XtPointer client_data,
					  XmPushButtonCallbackStruct *cbs)
{
	system("/sbin/shutdown -h now");
}

void b_rebootPushed(Widget w, XtPointer client_data,
					XmPushButtonCallbackStruct *cbs)
{
	system("/sbin/reboot");
}

