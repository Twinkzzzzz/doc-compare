Dim strFilt
Dim sFName
Dim strTitle
strFilt = "Word文档(*.doc;*.docx;*.docm),*.doc;*.docx;*.docm,"
strTitle = "打开Word文档"
sFName = Application.GetOpenFilename("Word文档(*.doc;*.docx;*.docm),*.doc;*.docx;*.docm,")
