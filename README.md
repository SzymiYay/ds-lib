# Data Strucure Library

DS-Lib is a C library for dealing with data structures.

## Compilation

Compile
```bash
make
```
Run
```bash
./run
```
Debug
```bash
make debug
```

## Usage
Sample use in main.c
```c
int main() {

    Queue* queue = ds_create_queue(0);
    ds_info_queue(queue);

    ds_enqueue(queue, 10);
    ds_enqueue(queue, 66);
    ds_enqueue(queue, 7);
    ds_print_queue(queue);

    ds_dequeue(queue);
    ds_dequeue(queue);

    ds_info_queue(queue);

    ds_free_queue(queue);

    return 0;
}
```

## List of implemented functions
1. Dynamic Array
2. Linked List
3. Stack
4. Queue

## Contribute
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Support
If you are having issues, please let us know.
We have a mailing list located at: mail@mail.mail

## License
[MIT](https://choosealicense.com/licenses/mit/)
