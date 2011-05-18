'''
    decorator
    decorate function
'''

from functools import wraps
import traceback
import logging

logger = logging.getLogger('lcd')

def catchExcept(err):
    def wrap(f):
        @wraps(f)
        def wrapped_f(*args, **kwargs):
            try:
                return f(*args, **kwargs)
            except Exception:
                logger.error(traceback.format_exc())
                return err
        return wrapped_f
    return wrap
    
    
@catchExcept(Exception('main()'))
def main(argv=None):
    '''
    Main function
    '''
    
    if argv is None:
        argv = sys.argv
    
    print 'Such a good day.'