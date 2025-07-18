import sys
from stm_ai_runner import AIRunner

runner = AIRunner();
runner.connect("serial")

runner.summary()