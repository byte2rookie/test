code='OK' #我们要传输的消息
code = 'OK'.encode('utf-8')  #'转化为字符编码后的消息'
print(code)
print(code.hex())#对字符编码进行十六进制转化后的消息
print(code.hex().encode('utf-8'))#对十六进制转化后的再用二进制编码传输的消息


#为什么我们会这么转化呢，因为通过实践发现，实际上USART传递的都是二进制编码的十六进制的消息信息
#接下来我们定义一下信息转化函数
def conv_message(message):
    code1=message.encode('utf-8')
    code2=code1.hex()
    code3=code2.encode('utf-8')
    print('命令已转换为编码:',code3)
    return code3

