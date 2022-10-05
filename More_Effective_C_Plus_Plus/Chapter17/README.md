考虑使用Lazy evaluation
主要是对于非常消耗资源的部分进行延迟执行，采取部分加载，例如加大文件时使用时才加载
class LargeObject
{
    public:
        LargeObject(Object ID): oid(ID), field1Value(0), field2Value(0), field3Value(0), field4Value(0)
        {}
        const string& field1() const
        {
            if (field1Value == 0)
            {
                do some things;
            }
            return *field1Value;
        }
    private:
        ObjectID oid;
        mutable std::string *field1Value;
        mutable int *field2Value;
        mutable double *field3Value;
        mutable std::string *field4Value;
}

其中mutable主要是用于延迟修改变量，其作用主要用于const函数中个修改变量。