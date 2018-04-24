Sub IMPORT_DATA()
Dim FSO As Scripting.FileSystemObject
Set FSO = New Scripting.FileSystemObject

'Folder should be where Temp_Log is saved on SD Card
Dim FOL As Scripting.Folder
'File location must be updated depending on users computer
Set FOL = FSO.GetFolder("D:\Documents\School\TempLog")
R = 1
Dim MYFILE As Scripting.File
Dim MYTEXTFILE As Scripting.TextStream
Dim DataStream As Boolean
Dim DataCounter As Long
Dim LoopCounter As Long
Dim Array1() As Variant
Dim Array2() As Variant
Dim Array3() As Variant
Dim Array4() As Variant
Dim Array5() As Variant
Dim Array6() As Variant
Dim Array7() As Variant
Dim Array8() As Variant
Dim TimeArray1() As Variant
Dim TimeArray2() As Variant
Dim TimeArray3() As Variant
Dim TimeArray4() As Variant
Dim TimeArray5() As Variant
Dim TimeArray6() As Variant
Dim TimeArray7() As Variant
Dim TimeArray8() As Variant

DataCounter = 0
DataStream = True
Innercounter = 1
Counter2 = 1

'Clear every cell in every sheet
Sheet1.Cells.Clear
Sheet2.Cells.Clear
Sheet3.Cells.Clear
Sheet4.Cells.Clear
Sheet5.Cells.Clear
Sheet6.Cells.Clear
Sheet7.Cells.Clear
Sheet8.Cells.Clear
Sheet9.Cells.Clear

For Each MYFILE In FOL.Files
    'MsgBox MYFILE.Name
    Set MYTEXTFILE = FSO.OpenTextFile("F:\TEMP_LOG.txt")
    'Set MYTEXTFILE = FSO.OpenTextFile(FOL & "\" & MYFILE.Name)
    Do While Not MYTEXTFILE.AtEndOfStream
        Cells(R, 1).Value = MYTEXTFILE.ReadLine
        R = R + 1
    Loop
MYTEXTFILE.Close
Next
'This creates 2 columns from the text file by seperating the values using a tab
    Columns("A:A").Select
    Selection.TextToColumns Destination:=Range("A1"), DataType:=xlDelimited, _
        TextQualifier:=xlDoubleQuote, ConsecutiveDelimiter:=False, Tab:=True, _
        Semicolon:=False, Comma:=False, Space:=False, Other:=False, FieldInfo _
        :=Array(Array(1, 1), Array(2, 1)), TrailingMinusNumbers:=True

cellCount = Worksheets("Sheet1").Cells(Rows.Count, 1).End(xlUp).Row
For i = 1 To cellCount
'If the it has seen "NEW RUN" once then import the values into the sheet
    If Worksheets("Sheet1").Cells(i, 1).Value = "NEW RUN" Then
    DataCounter = DataCounter + 1
    Select Case DataCounter
    Case 1
        For c = 2 To cellCount
        'If it has not seen another "NEW RUN" entry indicating that the trial is ended, it will read in the next value form the text file to Excel
            If (Worksheets("Sheet1").Cells(c, 1).Value <> "NEW RUN" And DataStream = True) Then
                ReDim Preserve Array1(c)
                ReDim Preserve TimeArray1(c)
                
                Array1(c) = Cells(c, 1).Value
                Worksheets("Sheet2").Cells(c - 1, 1).Value = Array1(c)
                
                TimeArray1(c) = Cells(c, 2).Value
                Worksheets("Sheet2").Cells(c - 1, 2).Value = TimeArray1(c)
                
                Innercounter = Innercounter + 1
        'If it does read "NEW RUN", then stop reading data and check to see if a new sheet is needed
            Else: DataStream = False
            End If
        Next
    'This process repeats up to 8 times
    Case 2
        DataStream = True
        Start2 = UBound(Array1) + 2
        For c = Start2 To cellCount
            If (Worksheets("Sheet1").Cells(c, 1).Value <> "NEW RUN" And DataStream = True) Then
                ReDim Preserve Array2(c)
                ReDim Preserve TimeArray2(c)
                
                Array2(c) = Cells(c, 1).Value
                Worksheets("Sheet3").Cells(c - (Start2 - 1), 1).Value = Array2(c)
                
                TimeArray2(c) = Cells(c, 2).Value
                Worksheets("Sheet3").Cells(c - (Start2 - 1), 2).Value = TimeArray2(c)
            Else: DataStream = False
            End If
        Next
        
    Case 3
        DataStream = True
        Start3 = UBound(Array2) + 2
        For c = Start3 To cellCount
            If (Worksheets("Sheet1").Cells(c, 1).Value <> "NEW RUN" And DataStream = True) Then
                ReDim Preserve Array3(c)
                ReDim Preserve TimeArray3(c)
                
                Array3(c) = Cells(c, 1).Value
                Worksheets("Sheet4").Cells((c - (Start3 - 1)), 1).Value = Array3(c)
                
                TimeArray3(c) = Cells(c, 2).Value
                Worksheets("Sheet4").Cells((c - (Start3 - 1)), 2).Value = TimeArray3(c)
            Else: DataStream = False
            End If
        Next
        
    Case 4
        DataStream = True
        Start4 = UBound(Array3) + 2
        For c = Start4 To cellCount
            If (Worksheets("Sheet1").Cells(c, 1).Value <> "NEW RUN" And DataStream = True) Then
                ReDim Preserve Array4(c)
                ReDim Preserve TimeArray4(c)
                
                Array4(c) = Cells(c, 1).Value
                Worksheets("Sheet5").Cells((c - (Start4 - 1)), 1).Value = Array4(c)
                
                TimeArray4(c) = Cells(c, 2).Value
                Worksheets("Sheet5").Cells((c - (Start4 - 1)), 2).Value = TimeArray4(c)
            Else: DataStream = False
            End If
        Next
        
    Case 5
        DataStream = True
        Start5 = UBound(Array4) + 2
        For c = Start5 To cellCount
            If (Worksheets("Sheet1").Cells(c, 1).Value <> "NEW RUN" And DataStream = True) Then
                ReDim Preserve Array5(c)
                ReDim Preserve TimeArray5(c)
                
                Array5(c) = Cells(c, 1).Value
                Worksheets("Sheet6").Cells((c - (Start5 - 1)), 1).Value = Array5(c)
                
                TimeArray5(c) = Cells(c, 2).Value
                Worksheets("Sheet6").Cells((c - (Start5 - 1)), 2).Value = TimeArray5(c)
            Else: DataStream = False
            End If
        Next
        
    Case 6
        DataStream = True
        Start6 = UBound(Array5) + 2
        For c = Start6 To cellCount
            If (Worksheets("Sheet1").Cells(c, 1).Value <> "NEW RUN" And DataStream = True) Then
                ReDim Preserve Array6(c)
                ReDim Preserve TimeArray6(c)
                
                Array6(c) = Cells(c, 1).Value
                Worksheets("Sheet7").Cells((c - (Start6 - 1)), 1).Value = Array6(c)
                
                TimeArray6(c) = Cells(c, 2).Value
                Worksheets("Sheet7").Cells((c - (Start6 - 1)), 2).Value = TimeArray6(c)
            Else: DataStream = False
            End If
        Next
        
    Case 7
        DataStream = True
        Start7 = UBound(Array6) + 2
        For c = Start7 To cellCount
            If (Worksheets("Sheet1").Cells(c, 1).Value <> "NEW RUN" And DataStream = True) Then
                ReDim Preserve Array7(c)
                ReDim Preserve TimeArray7(c)
                
                Array7(c) = Cells(c, 1).Value
                Worksheets("Sheet8").Cells((c - (Start7 - 1)), 1).Value = Array7(c)
                
                TimeArray7(c) = Cells(c, 2).Value
                Worksheets("Sheet8").Cells((c - (Start7 - 1)), 2).Value = TimeArray7(c)
            Else: DataStream = False
            End If
        Next
        
    Case 8
        DataStream = True
        Start8 = UBound(Array7) + 2
        For c = Start8 To cellCount
            If (Worksheets("Sheet1").Cells(c, 1).Value <> "NEW RUN" And DataStream = True) Then
                ReDim Preserve Array8(c)
                ReDim Preserve TimeArray8(c)
                
                Array8(c) = Cells(c, 1).Value
                Worksheets("Sheet9").Cells((c - (Start8 - 1)), 1).Value = Array8(c)
                
                TimeArray8(c) = Cells(c, 2).Value
                Worksheets("Sheet9").Cells((c - (Start8 - 1)), 2).Value = TimeArray8(c)
            Else: DataStream = False
            End If
        Next
        
    End Select
    
    End If
Next
MsgBox "Done!"
End Sub