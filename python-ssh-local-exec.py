import subprocess
import paramiko


def run(cmd_list):
    out = []
    err = []

    for cmd in cmd_list:
        args = cmd.split()
        proc = subprocess.Popen(args,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE)
        (stdoutdata, stderrdata) = proc.communicate()
        out.append(stdoutdata)
        err.append(stderrdata)
        return out, err


def sshRun(ip, cmd, username):
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    ssh.load_system_host_keys()
    ssh.connect(ip, username=username)
    print('running ssh on ', ip)
    ssh_stdin, ssh_stdout, ssh_stderr = ssh.exec_command(cmd)
    outlines = ssh_stdout.readlines()
    resp = ''.join(outlines)
    # print('in',ssh_stdin, 'out', ssh_stdout )
    return ssh_stdin, resp, ssh_stderr
