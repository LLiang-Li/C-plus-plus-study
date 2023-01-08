# 代码的命名

## 名字的重要性

以下两段代码的对比(JAVA)

public List<int []> getThem(){  
  List<int[]> list1 = new ArrayList<int[]>();  
  for(int[]x :theList)   
    if(x[0] == 4)  
      list1.add(x);  
   return list1;  
}  
可将代码修改如下：  
public List<Cell> getFlagCells(){  
  List<Cell> FlagCells = new ArrayList<Cell>();  
  for(Cell cell :GameBoard)   
    if(cell.isFlaged())  
      FlagCells.add(cell);  
   return FlagCells;  
}  
修改之后可读性大大增强，有利于后期的维护  

## 名字需要做唯一且有意义的区分
如下三个函数的意义无法区分：  
getActiveAccount()  
getActiveAccounts()  
getActiveAccountInfo()  

## 避免使用编码
使用编码徒增了解码的负担

## 类名
类名的对象名应该是名词或者名词短语  
方法名应该是动词或车动词短语

## 添加有意义的语境
语境不明确的如下：  
private void printGuessStatistic(char candidate, int counter){  
  string number;  
  string verb;  
  string pluralModifier;  
  if(0 == counter){  
    number = "no";
    verb = "are";  
    pluralModifier = "s"  
  }elseif(1 == counter){  
    number = "l";  
    verb = "is";  
    pluralModifier = ""   
  }else {  
    number = Integer.toString(counter);  
    verb = "are";  
    pluralModifier = "s";  
  }  
  string guessmessage = string.format("There %s %s %s%s",
                                      verb, number, candidate,
                                      pluralModifier);  
  print(guessmessage);
}  
比较好的
public class GuessStatisticsMessage{  
  private string Number;  
  private string Verb;  
  private string Plural_Modifier;  
  public string make(char Candidate, int count){  
    CreatePluraDependentMessageParts(count);  
    return string.format("There %s %s %s%s",
                                      Verb, Number, Candidate,
                                      Plural_Modifier);  
  }  
  private void CreatePluralDependentMessage(int count){  
    if(0 == count){  
      ThereAreNoletters();  
    } elseif(1 == count){  
      ThereIsOneLetter();
    } else{  
      ThereManyLetters(count);  
    }  
  }  
  private void ThereAreNoletters(){  
    Number = "no";  
    Verb = "are";  
    PluralModifier = "s";  
  }
  private void ThereIsOneLetter(){  
    Number = "1";  
    Verb = "is";  
    PluralModifier = "";  
  }
  private void ThereManyLetters(int count){  
    Number = Integer.toString(count);  
    Verb = "are";  
    PluralModifier = "s";  
  }
}