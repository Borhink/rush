import lldb

def reverse(debugger, command, result, dict):
	target = debugger.GetSelectedTarget()
	if (target):
		reverse_target = str(target)[::-1]
		print 'FT_' + reverse_target
	else:
		print target

def __lldb_init_module (debugger, dict):
	debugger.HandleCommand('command script add -f reverse.reverse reverse')
