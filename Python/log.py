import logging
import optparse

LOGGING_LEVELS = {'critical': logging.CRITICAL,
                  'error': logging.ERROR,
                  'warning': logging.WARNING,
                  'info': logging.INFO,
                  'debug': logging.DEBUG}

def main():
  parser = optparse.OptionParser()
  parser.add_option('-l', '--logging-level', help='Logging level')
  parser.add_option('-f', '--logging-file', help='Logging file name')
  (options, args) = parser.parse_args()
  logging_level = LOGGING_LEVELS.get(options.logging_level, logging.NOTSET)
  
  logging.basicConfig(level=logging_level,
                      filename=options.logging_file,
                      format='%(asctime)s %(levelname)s: %(message)s',
                      datefmt='%Y-%m-%d %H:%M:%S'
                      # will clear previous log content
                      filemode='w')
                      
  logging.debug('Test')


if __name__ == '__main__':
  main()
  
  
  
# ===================================================================
''' rotate log, split log files when size limit is reached '''

logLevel = logging.DEBUG
lcdLogger = logging.getLogger('lcd')    
lcdLogger.setLevel(logLevel)
formatter = logging.Formatter(
    "%(asctime)s-%(name)s-%(levelname)s-%(pathname)s(%(funcName)s): %(message)s")
rfh = logging.handlers.RotatingFileHandler(
    'lcd.log',
    maxBytes=1024*1024,
    backupCount=2)
rfh.setFormatter(formatter)
lcdLogger.addHandler(rfh)


