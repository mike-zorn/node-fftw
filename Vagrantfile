# -*- mode: ruby -*-
# vi: set ft=ruby :

$script = <<SCRIPT
echo provisioning...
apt-get update
apt-get install -y curl build-essential gdb
curl -sL https://deb.nodesource.com/setup | sudo bash -
apt-get install -y nodejs-dbg
npm install -g node-gyp
SCRIPT

# Vagrantfile API/syntax version. Don't touch unless you know what you're doing!
VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box = "hashicorp/precise64"
  config.vm.provision "shell", inline: $script
end
