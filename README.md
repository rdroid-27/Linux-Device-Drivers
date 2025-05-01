# Linux-Device-Drivers
# Setting Up the Sandbox Environment

This guide walks you through setting up an Ubuntu VM using **Multipass** and **VirtualBox** as the hypervisor, especially for systems where **Hyper-V is not available** (e.g., Windows Home Edition).

## Prerequisites

- **Install Multipass**: https://canonical.com/multipass/install  
- **Install VirtualBox**: https://www.virtualbox.org/wiki/Downloads

## Set Up Multipass

Open **Command Prompt (CMD)** as Administrator and restart the Multipass service:

```
net stop Multipass
net start Multipass
```

Check available networks:

```
multipass networks
```

Find the name of the network that has internet access (e.g., `Wi-Fi`).

Launch the Ubuntu VM with the appropriate network:

```
multipass launch --network Wi-Fi --name primary
```

Verify that the instance is running:

```
multipass list
```

## Access and Configure the VM

Enter the Ubuntu VM shell:

```
multipass shell
```

Enable password-based SSH login:

1. Open the SSH configuration file:

   ```
   sudo vim /etc/ssh/sshd_config
   ```

2. Find the line that says:

   ```
   PasswordAuthentication no
   ```

   and change it to:

   ```
   PasswordAuthentication yes
   ```

3. Save and exit the file.

4. Reload SSH configuration and restart the service:

   ```
   sudo systemctl daemon-reload
   sudo service ssh restart
   ```

5. Set a password for the `ubuntu` user:

   ```
   sudo passwd ubuntu
   ```

## Done

You can now SSH into your Ubuntu Multipass VM using the `ubuntu` user and the password you set, either from **VS Code** or any other SSH client.


## Install Essential Build Tools in the VM

Once inside the Ubuntu shell, update the package lists, upgrade installed packages, and install the necessary build tools and kernel headers:

```
sudo apt update
sudo apt upgrade
sudo apt install -y build-essential linux-headers-$(uname -r) kmod
```
