class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        i = 0
        while i<len(data):
            if data[i]&0xFF&0x80==0x00:
                i+=1
            elif data[i]&0xFF&0xE0 == 0xC0:
                i+=1
                if i<len(data) and data[i]&0xFF&0xC0 == 0x80:
                    i+=1
                else:
                    return False
            elif data[i]&0xFF&0xF0 == 0xE0:
                i+=1
                if i+1<len(data) and data[i]&0xFF&0xC0 == 0x80 and data[i+1]&0xFF&0xC0 == 0x80:
                    i+=2
                else:
                    return False
            elif data[i]&0xFF&0xF8 == 0xF0:
                i+=1
                if i+2<len(data) and data[i]&0xFF&0xC0 == 0x80 and data[i+1]&0xFF&0xC0 == 0x80 and data[i+2]&0xFF&0xC0 == 0x80:
                    i+=3
                else:
                    return False
            else:
            	return False
        return True
