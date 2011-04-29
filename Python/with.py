'''
    with statement
'''
# no need to close f.close() explicityly
with open("x.txt") as f:
    data = f.read()
    #do something with data
    
# ------------------------------------------------------------------------------
# the return value by __enter__ is assigned to "thing"
# the __exit__ method is executed no matter what happened:
#     To suppress the exception, just return a true 
#     the following __exit__ method swallows any TypeError,
#     but lets all other exceptions through
class controlled_execution:
    def __enter__(self):
        #set things up
        return thing
    #
    def __exit__(self, type, value, traceback):
        return isinstance(value, TypeError)

with controlled_execution() as thing:
     #some code
     pass
