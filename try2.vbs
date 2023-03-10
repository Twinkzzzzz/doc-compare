Function BrowseForFile()
    Dim shell : Set shell = CreateObject("Shell.Application")
    Dim file : Set file = shell.BrowseForFolder(0, "Choose a file:", &H4000, "C:\")
    BrowseForFile = file.self.Path
End Function

MsgBox BrowseForFile