# 關於"在網站交作業"常見錯誤指南


## 我的輸出在`vscode`或`devc++`沒有錯，但是在網頁上顯示錯誤

1. 您的請輸出沒有`換行`包含`指引輸入`!

  >[!note]
  >由於網站和對方式與CPE都是採用`輸出格式完全一致`判別，故缺少`\n`(換行)即不正確，
  >請看以下範例

✅ **正確**
```cpp

// 作業 2
cout << "請輸入存款金額" << endl; 

// 或是
cout << "請輸入存款金額\n";

//或是
cout << "請輸入存款金額";
cin >> m;
cout << endl;
```
❌ **錯誤**
```cpp

cout << "請輸入存款金額" << endl; // 輸出完成缺少換行 ， 故判定錯誤 
cin >> m;
```

2. 字元缺失
- 即缺字或字體拼寫錯誤，例如:

```cpp
cout << "請輸入存款金額" << endl;  // 正確
cout << "存款金額" << endl; // 缺少字元
```

3. `:`分歧

>[!note]
>題目皆是使用**中文輸入法**的`:`而不是英文輸入法的`:`


## 仍有錯誤問題

當批改結果顯示錯誤後

![](https://github.com/archie0732/c-solution/blob/main/picture/Screenshot%202025-05-03%20201637.png)








請複製連結，並在ta時間來507找我，感恩


![](https://github.com/archie0732/c-solution/blob/main/picture/Screenshot%202025-05-03%20201659.png)




-# auto-check-hw @ 2025 by arch1e 

