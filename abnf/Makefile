# Download ABNF Compiler from https://github.com/zinid/abnfc
ABNFC=abnfc
SIP_RL=../c_src/sip.rl

all: $(SIP_RL)

$(SIP_RL): basic.abnf uri.abnf sip.abnf
	$(ABNFC) core basic.abnf uri.abnf sip.abnf -i -n sip -o $(SIP_RL)

clean:
	rm -f $(SIP_RL)
