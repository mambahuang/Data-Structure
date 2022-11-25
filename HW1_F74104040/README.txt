我利用兩個header file(transpose, ftranspose)去分別寫Transpose 和 Fast Transpose，最後兩個檔案都回傳transpose好的matrix。
而時間是利用clock()這個函式去計算開始的時間和結束的時間，start和end分別寫在函式的開始和結束，兩個
再相減，就會得到花費的時間。最後將結果寫入p2.txt中。