
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {
    uint public balance;

    // Deposit money
    function deposit() public payable {
        require(msg.value > 0, "Amount must be greater than zero");
        balance += msg.value;
    }

    // Withdraw money
    function withdraw(uint amount) public {
        require(amount > 0, "Amount must be greater than zero");
        require(amount <= balance, "Insufficient balance");

        balance -= amount;
        payable(msg.sender).transfer(amount);
    }

    // Show balance
    function showBalance() public view returns (uint) {
        return balance;
    }
}



---------------------------


// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract BankAccount {
    mapping(address => uint256) private balances;

    event Deposit(address indexed account, uint256 amount);
    event Withdraw(address indexed account, uint256 amount);

    function deposit() public payable {
        require(msg.value > 0, "Deposit amount must be greater than 0");

        balances[msg.sender] += msg.value;

        emit Deposit(msg.sender, msg.value);
    }

    function withdraw(uint256 amount) public {
        require(amount > 0, "Withdraw amount must be greater than 0");
        require(balances[msg.sender] >= amount, "Insufficient balance");

        // Update balance before sending ETH
        balances[msg.sender] -= amount;

        // Send ETH
        (bool success, ) = payable(msg.sender).call{value: amount}("");

        require(success, "ETH transfer failed");

        emit Withdraw(msg.sender, amount);
    }

    function getBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}