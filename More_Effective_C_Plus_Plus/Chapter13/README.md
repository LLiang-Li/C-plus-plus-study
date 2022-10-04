以by reference方式捕捉exceptions
必须使用引用方式：
    catch(std::exception &e)
采用value的方式会出现复制，只会复制静态对象
不需使用以下捕捉：
    catch(std::exception e)