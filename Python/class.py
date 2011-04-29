'''
    Python class
'''

class Animal(object):
    name = ''
    
    
    def __init__(self, name):
        self.name = name
        
    def getName(self):
        return self.name
    

class Dog(Animal):
    def __init__(self, name=''):
        super(Dog, self).__init__(name)
        print 'Create dog complete.'
    
    def getName(self):
        '''
        Override
        '''
        return 'John Mary'
