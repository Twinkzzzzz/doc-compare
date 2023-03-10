Option Explicit

Dim objWord, objDoc
Dim str1
Dim pg
Dim FSO, TxtFile
Dim args
Dim WordFileName,TxtFileName
Dim wShell
Dim oExec

Set wShell = CreateObject("WScript.Shell")
Set oExec = wShell.Exec("mshta.exe ""about:<input type=file id=FILE><script>FILE.click();new ActiveXObject('Scripting.FileSystemObject').GetStandardStream(1).WriteLine(FILE.value);close();resizeTo(0,0);</script>""")
WordFileName = oExec.StdOut.ReadLine

Set args = WScript.Arguments
If args.Count = 1 Then
	TxtFileName = WScript.Arguments(0)
Else
	MsgBox "Fail to choose a file!"
	wscript.quit
End If

Set objWord=CreateObject("Word.application")
objWord.visible = False
Set objDoc=objWord.Documents.Open(WordFileName)

Set FSO = CreateObject("Scripting.FileSystemObject")
Set TxtFile = FSO.CreateTextFile(TxtFileName, True)

With objWord.ActiveDocument
    	For Each pg In .Paragraphs
        		str1 = pg.Range.Text
		TxtFile.Write str1
    	Next
End With

TxtFile.Close
objDoc.Close
objWord.Quit
Set objWord = Nothing