#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

; Personal keystrokes

^+t::  Winset, Alwaysontop, , A ; Keep on top Ctrl-Shift-t

#c::	; <-- Open/Activate/Minimize Windows Calculator
{
	if WinExist("Calculator ahk_class CalcFrame") or WinExist("Calculator ahk_class ApplicationFrameWindow")
		if WinActive()
			WinMinimize
		else
			WinActivate
	else
		Run calc.exe
	return
}

; Keyboard Shortcut
:*oc?:|email::
sendinput your email here
Return

:*oc?:|weather::
Run https://sitename
Return

; Push button scripts
; Push buttons are mapped as F13-F24 in Arduino Pro Micro
F13:: return
F14:: return
F15:: WebSite_Clipboard("https://translate.google.com/#view=home&op=translate&sl=auto&tl=zh-TW&text=","","https://translate.google.com/")
F16:: WebSite_Clipboard("https://hk.dictionary.search.yahoo.com/search;?p=","&fr=sfp&iscqry=","https://hk.dictionary.search.yahoo.com/")
F17:: WebSite_Clipboard("https://www.youtube.com/results?search_query=","","https://www.youtube.com/")
F18:: WebSite_Clipboard("https://www.google.com.hk/search?q=","","http://www.google.com")
F20:: return

; Logical button scripts
; Page 1 Start
<+F13:: return
<!F13:: return
<#F13:: return
<^F13:: return
>+F13:: return
>!F13:: return
>#F13:: return
>^F13:: return
<!<+F13:: return
<#<+F13:: return
<#<!F13:: return
<^<+F13:: return
<^<!F13:: return
<^<#F13:: return
<!>+F13:: return
<#>+F13:: return
<^>+F13:: return
>!<+F13:: return
<#>!F13:: return
<^>!F13:: return
>!>+F13:: return
>#<+F13:: return
>#<!F13:: return
<^>#F13:: return
>#>+F13:: return
>#>!F13:: return
>^<+F13:: return
>^<!F13:: return
>^<#F13:: return
>^>+F13:: return
>^>!F13:: return
>^>#F13:: return
<#<!<+F13:: return
<^<!<+F13:: return
<^<#<+F13:: return
<^<#<!F13:: return
<#<!>+F13:: return
<^<!>+F13:: return
<^<#>+F13:: return
<#>!<+F13:: return
; Page 1 End

; Page 2 Start
<^>!<+F13:: return
<^<#>!F13:: return
<#>!>+F13:: return
<^>!>+F13:: return
>#<!<+F13:: return
<^>#<+F13:: return
<^>#<!F13:: return
>#<!>+F13:: return
<^>#>+F13:: return
>#>!<+F13:: return
<^>#>!F13:: return
>#>!>+F13:: return
>^<!<+F13:: return
>^<#<+F13:: return
>^<#<!F13:: return
>^<!>+F13:: return
>^<#>+F13:: return
>^>!<+F13:: return
>^<#>!F13:: return
>^>!>+F13:: return
>^>#<+F13:: return
>^>#<!F13:: return
>^>#>+F13:: return
>^>#>!F13:: return
<^<#<!<+F13:: return
<^<#<!>+F13:: return
<^<#>!<+F13:: return
<^<#>!>+F13:: return
<^>#<!<+F13:: return
<^>#<!>+F13:: return
<^>#>!<+F13:: return
<^>#>!>+F13:: return
>^<#<!<+F13:: return
>^<#<!>+F13:: return
>^<#>!<+F13:: return
>^<#>!>+F13:: return
>^>#<!<+F13:: return
>^>#<!>+F13:: return
>^>#>!<+F13:: return
>^>#>!>+F13:: return
; Page 2 End

; Page 3 Start
<+F14:: return
<!F14:: return
<#F14:: return
<^F14:: return
>+F14:: return
>!F14:: return
>#F14:: return
>^F14:: return
<!<+F14:: return
<#<+F14:: return
<#<!F14:: return
<^<+F14:: return
<^<!F14:: return
<^<#F14:: return
<!>+F14:: return
<#>+F14:: return
<^>+F14:: return
>!<+F14:: return
<#>!F14:: return
<^>!F14:: return
>!>+F14:: return
>#<+F14:: return
>#<!F14:: return
<^>#F14:: return
>#>+F14:: return
>#>!F14:: return
>^<+F14:: return
>^<!F14:: return
>^<#F14:: return
>^>+F14:: return
>^>!F14:: return
>^>#F14:: return
<#<!<+F14:: return
<^<!<+F14:: return
<^<#<+F14:: return
<^<#<!F14:: return
<#<!>+F14:: return
<^<!>+F14:: return
<^<#>+F14:: return
<#>!<+F14:: return
; Page 3 End

; Page 4 Start
<^>!<+F14:: return
<^<#>!F14:: return
<#>!>+F14:: return
<^>!>+F14:: return
>#<!<+F14:: return
<^>#<+F14:: return
<^>#<!F14:: return
>#<!>+F14:: return
<^>#>+F14:: return
>#>!<+F14:: return
<^>#>!F14:: return
>#>!>+F14:: return
>^<!<+F14:: return
>^<#<+F14:: return
>^<#<!F14:: return
>^<!>+F14:: return
>^<#>+F14:: return
>^>!<+F14:: return
>^<#>!F14:: return
>^>!>+F14:: return
>^>#<+F14:: return
>^>#<!F14:: return
>^>#>+F14:: return
>^>#>!F14:: return
<^<#<!<+F14:: return
<^<#<!>+F14:: return
<^<#>!<+F14:: return
<^<#>!>+F14:: return
<^>#<!<+F14:: return
<^>#<!>+F14:: return
<^>#>!<+F14:: return
<^>#>!>+F14:: return
>^<#<!<+F14:: return
>^<#<!>+F14:: return
>^<#>!<+F14:: return
>^<#>!>+F14:: return
>^>#<!<+F14:: return
>^>#<!>+F14:: return
>^>#>!<+F14:: return
>^>#>!>+F14:: return
; Page End

; Page 5 Start
<+F15:: return
<!F15:: return
<#F15:: return
<^F15:: return
>+F15:: return
>!F15:: return
>#F15:: return
>^F15:: return
<!<+F15:: return
<#<+F15:: return
<#<!F15:: return
<^<+F15:: return
<^<!F15:: return
<^<#F15:: return
<!>+F15:: return
<#>+F15:: return
<^>+F15:: return
>!<+F15:: return
<#>!F15:: return
<^>!F15:: return
>!>+F15:: return
>#<+F15:: return
>#<!F15:: return
<^>#F15:: return
>#>+F15:: return
>#>!F15:: return
>^<+F15:: return
>^<!F15:: return
>^<#F15:: return
>^>+F15:: return
>^>!F15:: return
>^>#F15:: return
<#<!<+F15:: return
;<^<!<+F15:: return
;<^<#<+F15:: return
;<^<#<!F15:: return
;<#<!>+F15:: return
;<^<!>+F15:: return
;<^<#>+F15:: return
;<#>!<+F15:: return
; Page 5 End

;Premiere Media Color Labelling
Label_Color(Num){ 
	if winactive("ahk_exe Adobe Premiere Pro.exe"){
		MouseClick, Left
		sleep 100
		WinActivate, Adobe Premiere Pro 
		sendinput !e
		sleep 10
		sendinput l
		sleep 10
		if (Num==0){
			sendinput s
		} else {
			sendinput {Down %Num%}
			sleep 10
			SendInput {Enter}
		}
	} return
}

;將關鍵字帶入網址查詢(version:190624)
WebSite_Clipboard(UrlA,UrlB,website_name:=""){
    ;備份並清空剪貼簿
    clipboard_save = %ClipboardAll%
    Clipboard :=""
    ;獲取選取的關鍵字
    Send ^{c}
    Sleep 200
    keyWord = %Clipboard%
    ;恢復先前的剪貼簿
    Clipboard = %clipboard_save%
    ;若沒有選取文字被選取，則跳出輸入文字框讓使用者輸入關鍵字，複製到剪貼簿
    if (keyWord=""){
        ;若未設定網站名稱，則用
        Run %website_name%
    }
    ;將關鍵字做解碼處理，並嵌入搜尋網址中
    if (ErrorLevel=0 and keyWord!=""){
        Copy= % UriEncode(keyWord)
        Run %UrlA%%Copy%%UrlB%
    }
    return
}

;讓關鍵字轉化為網址解碼形式，得以讓關鍵字正確被搜尋
;參考自https://rosettacode.org/wiki/URL_encoding#AutoHotkey
UriEncode(Uri){
    VarSetCapacity(Var, StrPut(Uri, "UTF-8"), 0)
    StrPut(Uri, &Var, "UTF-8")
    f := A_FormatInteger
    SetFormat, IntegerFast, H
    While Code := NumGet(Var, A_Index - 1, "UChar")
        If (Code >= 0x30 && Code <= 0x39 ; 0-9
            || Code >= 0x41 && Code <= 0x5A ; A-Z
            || Code >= 0x61 && Code <= 0x7A) ; a-z
            Res .= Chr(Code)
        Else
            Res .= "%" . SubStr(Code + 0x100, -1)
    SetFormat, IntegerFast, %f%
    Return, Res
}

; Search by Premiere, VS Code, Chrome and File Explorer
F19::
    if winactive("ahk_exe Adobe Premiere Pro.exe")
        {
        if IsFunc("effectsPanelType") {
        Func := Func("effectsPanelType")
        RetVal := Func.Call(directory,"")
        ;;I'm doing it in this weird way just in case the function is not available -- this means it won't screw anything up.
        }
        ;effectsPanelType("") ;set to macro key G1 on my logitech G15 keyboard. 
        
        ;This just CLEARS the effects panel search bar and selects it so that you can type something in yourself. Or maybe it merely highlights what it already there -- whatever.
        }
    else if winactive("ahk_exe code.exe")
        sendinput ^f
    else if winactive("ahk_exe chrome.exe")
        sendinput ^e
    else if winactive("ahk_class CabinetWClass")
        sendinput ^e
Return ; F19 End

; File Explorer
F21::
    IfWinNotExist, ahk_class CabinetWClass
        Run, explorer.exe
    GroupAdd, myexplorers, ahk_class CabinetWClass
    if WinActive("ahk_exe explorer.exe")
        GroupActivate, myexplorers, r
    else
        WinActivate ahk_class CabinetWClass ;you have to use WinActivatebottom if you didn't create a window group.

    ;maybe need to unstick modifiers
    sleep 2
    send, {Rctrl up}
    send, {Lctrl up}
Return ; F21 End

; Chrome
F22::
    IfWinNotExist, ahk_exe chrome.exe
        Run, chrome.exe

    if WinActive("ahk_exe chrome.exe")
        Sendinput ^{tab}
    else
        WinActivate ahk_exe chrome.exe
    ;maybe need to unstick modifiers
    sleep 2
    send, {Rctrl up}
    send, {Lctrl up}
Return ; F22 End

; Microsoft Word
F23::
Process, Exist, WINWORD.EXE
 ;msgbox errorLevel `n%errorLevel%
	 If errorLevel = 0
		 Run, WINWORD.EXE
	 else
	 {
	GroupAdd, mywords, ahk_class OpusApp
	if WinActive("ahk_class OpusApp")
		GroupActivate, mywords, r
	else
		WinActivate ahk_class OpusApp
     }
Return ; F23 End

; Adobe Premiere
F24::
IfWinNotExist, ahk_class Premiere Pro
	{
	;Run, Adobe Premiere Pro.exe
	;Adobe Premiere Pro CC 2017
	; Run, C:\Program Files\Adobe\Adobe Premiere Pro CC 2017\Adobe Premiere Pro.exe ;if you have more than one version instlaled, you'll have to specify exactly which one you want to open.
	Run, Adobe Premiere Pro.exe
	}
if WinActive("ahk_class Premiere Pro")
	{
	;;update: this is no longer needed, they fixed that responsiveness issue AFAIK...
	; ; ; IfWinNotExist, ahk_exe notepad++.exe
		; ; ; {
		; ; ; Run, notepad++.exe
		; ; ; sleep 200
		; ; ; }
	; ; ; WinActivate ahk_exe notepad++.exe ;so I have this here as a workaround to a bug. Sometimes Premeire becomes unresponsive to keyboard input. (especially after timeline scrolling, especially with a playing video.) Switching to any other application and back will solve this problem. So I just hit the premiere button again, in those cases.g
	; ; ; sleep 10
	WinActivate ahk_class Premiere Pro
	}
else
	WinActivate ahk_class Premiere Pro

;maybe need to unstick modifiers
sleep 2
send, {Rctrl up}
send, {Lctrl up}
Return ; F24 End


;This is the real magic. With this script, you can PASTE those previously saved clipboard states, at any time.
#ifwinactive ahk_exe Adobe Premiere Pro.exe
recallClipboard(fname, transition := 0) {
	;deactivate keyboard and mouse
	;keyShower(int, "recallClipboard")
	if IsFunc("Keyshower") {
		Func := Func("Keyshower")
		RetVal := Func.Call(fname, "recallClipboard") 
	}
	WinActivate, Adobe Premiere Pro
	Send, +3 ;Focus "timeline" Shift-3
	;Send ^!d ;this is to deselect any clips that might be selected in the timeline.
	;tooltip, "now loading random text into the clipboard."
	loadFromFile("clipTEXT.clp") ;to create this file, just highlight some plain text, copy it, and use insideclipboard.exe to save it as clipTEXT.clp. The clipboard MUST have some text inside; it CANNOT be completely empty. This has the effect of DELETING all the aspects of the clipboard, EXCEPT for text.
	sleep 15
	; ; WinActivate, Adobe Premiere Pro ;IDK if this is needed here.
	; ; loadFromFile("clipTEXT.clp") ;The clipboard must be loaded twice, or it won't work about 70% of the time! I don't know why...
	; ; sleep 15
	;Autohotkey can now delete that string of text, so that no text is accidentlaly pasted into premiere. It doesn't seem to be able to delete EVERYTHING, so the above code is definitely necessary!
	clipboard = 
	;The clipboard is now completely empty.
	sleep 10
	
	;tooltip, now pasting NOTHING into premiere....
	WinActivate, Adobe Premiere Pro ;extremely important to ensure you are still active/focused on Premiere
	SendInput, {Shift Down}{Shift Up}
	sleep 10
	SendInput, {Ctrl Down}{v Down} ;this is a MUCH more robust way of using the keyboard shortcuts to PASTE, rather than just using "Send ^v"
	sleep 5
	SendInput, {v Up}{Ctrl Up}
	sleep 20
	
	;It is necessary to PASTE this COMPLETELY BLANK clipboard into premiere, or Premiere won't "know" that the clipboard has been completely emptied.
	;If you don't do this, Premiere will just use whatever thing you had previously copied inside of Premiere.
	clipboard = 
	;the above line is another method for clearing the clipboard that must also be done to ensure a totally empty clipboard
	sleep 30
	;tooltip, "clip" . %int% . ".clp" ;this code doesn't work
	;tooltip, now preparing to paste %int%
	;msgbox, %int%
	WinActivate, Adobe Premiere Pro 
	loadFromFile(fname) ;now we are loading the previously saved clipboard file!
	sleep 15
	; ; loadFromFile("clip" . int . ".clp") ;This must be done twice, or it doesn't work! I don't know why!! :D ;ADENDUM - i tried it with only 1 load and NOW it IS working??? IDK why
	; ; sleep 15
	WinActivate, Adobe Premiere Pro ;this is extremely important.... otherwise, it will try to paste into the command prompt or something. You must ensure the correct program is pasted into.
	
	; ; ; if (transition = 0)
	; ; ; {
		; ; ; target("v1", "off", "all", 5) ;this will disable all video layers, and enable only layer 5.
		; ; ; tooltip, only layer 5 was turned on should be
		; ; ; sleep 150
		
	; ; ; }
	tooltip, now PASTING into premiere...
	WinActivate, Adobe Premiere Pro
	SendInput, {Shift Down}{Shift Up}{Ctrl Down}{v Down}
	sleep 5
	SendInput, {v Up}{Ctrl Up}
	sleep 10
	
	if (transition = 0)
		;target("v1", "on", "all")
	sleep 10
	; send ^{F9} ;toggle video tracks (hopefully off)
	; send ^+{F9} ;toggle audio tracks (hopefully off)
	tooltip,
	Send, +3 ;Focus "timeline" Shift-3
	Send, ^+a ;deselect any clips Ctrl-Shift-a
	Send, {Up}
	
} ;end of recall Clipboard()

loadFromFile(name) {
	; You'll need to change these paths too!
	RunWait, %comspec% /c D:\insideclipboard\InsideClipboard.exe /loadclp %name%, D:\insideclipboard\clipboards\
}

; Presetted effects
; (Effect Name, Edit# of Effects panel, Relative X, Y mouse move)
#IfWinActive, ahk_exe Adobe Premiere Pro.exe
Preset_effect(efname, EditNos, Rx, Ry){
	sleep 100
	WinActivate, Adobe Premiere Pro
	Sendinput ^0 ; Force ime to ENG (Ctrl-0)
	SetKeyDelay , -1
	CoordMode , Mouse , Screen
	BlockInput , SendAndMouse
	BlockInput , MouseMove
	BlockInput , On
	MouseGetPos, posx , posy
	ControlGetPos , X , Y , W , H , %EditNos% , ahk_class Premiere Pro ; Modify your Edit# 
	Send +7 ; Modify your shortcut to Effects panel
	;sleep 500
	MouseMove, X, Y
	MouseMove, -500, 0, 0, R
	MouseMove, 50, 0, 0, R
	Click
	Sendinput ^a
	Sendinput %efname%
	MouseMove , %Rx%, %Ry%, 0, R  ;the MouseMove X,Y coordinates depending your screen size and scale factor
	Click
	sleep 700
	Click, down
	MouseMove, %posx% , %posy%
	Click, up
	Click   ; Click one time
	send ^\ ; Move playhead to cursor
	sendinput +5 ; Open Effect Control Panel
	Sendinput +3 ; Open Timeline
	sleep 10
	Sendinput v
	BlockInput off
	BlockInput Default
	BlockInput MouseMoveOff
	Return
}

#IfWinActive, ahk_exe Adobe Premiere Pro.exe
Preset_effect_test(efname, EditNos, Rx, Ry){
	sleep 100
	WinActivate, Adobe Premiere Pro
	Sendinput ^0 ; Force ime to ENG (Ctrl-0)
	SetKeyDelay , -1
	CoordMode , Mouse , Screen
	BlockInput , SendAndMouse
	BlockInput , MouseMove
	BlockInput , On
	MouseGetPos, posx , posy
	ControlGetPos , X , Y , W , H , %EditNos% , ahk_class Premiere Pro ; Modify your Edit# 
	Send +7 ; Modify your shortcut to Effects panel
	;sleep 500
	MouseMove, X, Y
	MouseMove, -500, 0, 0, R
	MouseMove, 50, 0, 0, R
	Click
	Sendinput ^a
	Sendinput %efname%
	MouseMove , %Rx%, %Ry%, 0, R  ;the MouseMove X,Y coordinates depending your screen size and scale factor
	/*Click
	sleep 700
	Click, down
	MouseMove, %posx% , %posy%
	Click, up
	Click   ; Click one time
	send ^\ ; Move playhead to cursor
	sleep 10
	Sendinput v
	*/
	BlockInput off
	BlockInput Default
	BlockInput MouseMoveOff
	Return
}